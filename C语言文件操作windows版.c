#include <stdio.h>
#include <io.h>
#include <windows.h>
int pt()
{
	printf("\t\tc�����ļ��ı�����windows��\n");
	printf("\t\t˵��:ֻ���ļ��к�'txt'�ı���ʽ��Ч\n");
	printf("\t\t·����ʽ����C:/��C:/windows��C:/windows/1.txt\n");
	printf("\t\t�ı�����Ҫ��'.txt'��׺\n");
	printf("\t\t1.�ļ��б�\n");
	printf("\t\t2.�½��ļ���\n");
	printf("\t\t3.�½��ı�\n");
	printf("\t\t4.ɾ���ļ���\n");
	printf("\t\t5.ɾ���ı�\n");
	printf("\t\t6.�����ı�\n");
	printf("\t\t7.�������ļ����ı�\n");
	printf("\t\t�������������˳�\n");
	printf("\t\t���������ѡ��:");
	int a;
	scanf("%d", &a);
	return a;
}
void set_console_color(unsigned short color_index)
{	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_index);
}
int setcolor()
{
	printf("��ɫ����\n");;
	set_console_color(1);
	printf("1.��ɫ\n");
	set_console_color(2);
	printf("2.��ɫ\n");
	set_console_color(3);
	printf("3.����ɫ\n");
	set_console_color(4);
	printf("4.��ɫ\n");
	set_console_color(5);
	printf("5.��ɫ\n");
	set_console_color(6);
	printf("6.��ɫ\n");
	set_console_color(7);
	printf("7.��ɫ\n"); 
	set_console_color(8);
	printf("8.��ɫ\n");
	set_console_color(9);
	printf("9.����ɫ\n");
	set_console_color(7);
	printf("������Ҫ��ʾ����ɫ����(����:��ʾ��ɫ,����1):");
	int a;
	scanf("%d", &a);
	if ((a > 9)||(a<=0))
	{
		printf("�������,����������:");	
		scanf("%d", &a);
	}
	return a;
}
int main()
{
	int color = setcolor();
	set_console_color(color);
	do
	{
		int a = pt();
		switch (a)
		{
		case 1:
			printf("������Ҫ�鿴�ļ��б��·��:");
			int b = 0;
			char sreachdir[255];
			scanf("%s", sreachdir);
			strcat(sreachdir, "/*");
			const char* sreach = sreachdir;
			struct _finddata_t FileInfo;
			long handle;
			handle = _findfirst(sreach, &FileInfo);
			if (-1 == handle)
			{
				printf("��ȡĿ¼ʧ��\n");
				break;
			}
			while (!_findnext(handle, &FileInfo))
			{
				++b;
				if (strcmp(FileInfo.name, "..") == 0)
				{
					continue;
				}
				printf("�ļ�%d: %s\t", b, FileInfo.name);
				if ((b % 1) == 0)
				{

					printf("\n");
				}
			}
			printf("\n");
			_findclose(handle);
			sreach = NULL;
			break;
		case 2:
			printf("��������Ҫ�½����ļ���·��:");
			char mkfile[255];
			scanf("%s", mkfile);
			if (mkdir(mkfile, 777) == -1)
			{
				printf("�½��ļ�����\n");
				break;
			}
			printf("�Ѵ����ļ���:%s\n", mkfile);
			break;
		case 3:
			printf("��������Ҫ�½����ı�·��:");
			FILE* fp;
			char mktxt[255];
			scanf("%s", mktxt);
			if ((fp = fopen(mktxt, "wt+")) == NULL)
			{
				printf("�½��ı�����\n");
				break;
			}
			printf("���½��ı�:%s\n", mktxt);
			fclose(fp);
			break;
		case 4:
			printf("��������Ҫɾ�����ļ�·��:");
			char dlfilename[255];
			scanf("%s", dlfilename);
			if ((rmdir(dlfilename)) == -1)
			{
				printf("ɾ���ļ�ʧ��\n");
				break;
			}
			printf("��ɾ���ļ�:%s\n", dlfilename);
			break;
		case 5:
			printf("��������Ҫɾ�����ı�·��:");
			char dltxtname[255];
			scanf("%s", dltxtname);
			if ((remove(dltxtname)) == -1)
			{
				printf("ɾ���ı�ʧ��\n");
				break;
			}
			printf("��ɾ���ı�:%s\n", dltxtname);
			break;
		case 6:
			printf("������Ҫ���Ƶ��ı�·��:");
			char cp;
			char oname[255];
			scanf("%s", oname);
			char nname[255];
			printf("�����븴�ƺ���ı�·��:");
			scanf("%s", nname);
			FILE* oldname = fopen(oname, "rb+");
			FILE* newname = fopen(nname, "wb+");
			while ((cp = fgetc(oldname)) != EOF)
			{
				fputc(cp, newname);
			}
			printf("�ı�:%s �Ѹ��Ƶ� %s\n", oname, nname);
			fclose(oldname);
			fclose(newname);
			break;
		case 7:
			printf("������Ҫ�������ļ����ı���·��:");
			char oldfilename[255];
			scanf("%s", oldfilename);
			char newfilename[255];
			printf("���������������ļ����ı���·��:");
			scanf("%s", newfilename);
			if ((rename(oldfilename, newfilename)) == -1)
			{
				printf("������ʧ��\n");
				break;
			}
			printf("�ļ����ı�:%s ��������Ϊ %s\n", oldfilename, newfilename);
			break;
		default:
			set_console_color(4);
			printf("�밴�����ȷ���˳�:");
			getch();
			printf("\n�˳���...");
			return 0;
			break;
		}
	} while (1);
}