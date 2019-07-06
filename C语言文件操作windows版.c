#include <stdio.h>
#include <io.h>
int pt()
{
	printf("\t\tc语言文件文本操作windows版\n");
	printf("\t\t说明:只对文件夹和'txt'文本格式有效\n");
	printf("\t\t路径格式举例C:/或C:/windows\n");
	printf("\t\t打开文本要加'.txt'后缀\n");
	printf("\t\t1.文件列表\n");
	printf("\t\t2.新建文件夹\n");
	printf("\t\t3.新建文本\n");
	printf("\t\t4.删除文件夹\n");
	printf("\t\t5.删除文本\n");
	printf("\t\t6.复制文本\n");
	printf("\t\t7.重命名文件或文本\n");
	printf("\t\t输入其他数字退出\n");
	printf("\t\t请输入你的选项:");
	int a;
	scanf("%d", &a);
	return a;
}
int main()
{
	do
	{
		int a = pt();
		switch (a)
		{
		case 1:
			printf("请输入要查看文件列表的路径:");
			int b = 0;
			char sreachdir[255];
			scanf("%s", sreachdir);
			strcat(sreachdir, "/*");
			const char* sreach = sreachdir;
			struct _finddata_t FileInfo;
			long handle;
			handle = _findfirst(sreach, &FileInfo);
			if (-1 == handle)
				return -1;

			while (!_findnext(handle, &FileInfo))
			{
				++b;
				if (strcmp(FileInfo.name, "..") == 0)
				{
					continue;
				}
				printf("文件%d: %s\t", b, FileInfo.name);
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
			printf("请输入你要新建的文件夹路径:");
			char mkfile[255];
			scanf("%s", mkfile);
			if (mkdir(mkfile, 777) == -1)
			{
				printf("新建文件错误\n");
				break;
			}
			printf("已创建文件夹:%s\n", mkfile);
			break;
		case 3:
			printf("请输入你要新建的文本路径:");
			FILE* fp;
			char mktxt[255];
			scanf("%s", mktxt);
			if ((fp = fopen(mktxt, "wt+")) == NULL)
			{
				printf("新建文本错误\n");
				break;
			}
			printf("已新建文本:%s\n", mktxt);
			fclose(fp);
			break;
		case 4:
			printf("请输入你要删除的文件路径:");
			char dlfilename[255];
			scanf("%s", dlfilename);
			if ((rmdir(dlfilename)) == -1)
			{
				printf("删除文件失败\n");
				break;
			}
			printf("已删除文件:%s\n", dlfilename);
			break;
		case 5:
			printf("请输入你要删除的文本路径:");
			char dltxtname[255];
			scanf("%s", dltxtname);
			if ((remove(dltxtname)) == -1)
			{
				printf("删除文本失败\n");
				break;
			}
			printf("已删除文本:%s\n", dltxtname);
			break;
		case 6:
			printf("请输入要复制的文本路径:");
			char cp;
			char oname[255];
			scanf("%s", oname);
			char nname[255];
			printf("请输入复制后的文本路径:");
			scanf("%s", nname);
			FILE* oldname = fopen(oname, "rb+");
			FILE* newname = fopen(nname, "wb+");
			while ((cp = fgetc(oldname)) != EOF)
			{
				fputc(cp, newname);
			}
			printf("文本:%s 已复制到 %s\n", oname, nname);
			fclose(oldname);
			fclose(newname);
			break;
		case 7:
			printf("请输入要重命名文件或文本的路径:");
			char oldfilename[255];
			scanf("%s", oldfilename);
			char newfilename[255];
			printf("请输入重命名后文件或文本的路径:");
			scanf("%s", newfilename);
			if ((rename(oldfilename, newfilename)) == -1)
			{
				printf("重命名失败\n");
				break;
			}
			printf("文件或文本:%s 已重命名为 %s\n", oldfilename, newfilename);
			break;
		default:
			return 0;
			break;
		}
	} while (1);
}
