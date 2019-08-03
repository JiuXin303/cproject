#include <stdio.h>
#include <malloc.h>
struct syllabus
{
	int classnum;
	char classname[255];
};
struct nodelist
{
	struct syllabus data;
	struct nodelist* next;
};
struct nodelist* creatclasslist()
{
	struct nodelist* classlist = (struct nodelist*)malloc(sizeof(struct nodelist));
	classlist->next = NULL;
	return classlist;
}
struct nodelist* creatclassnode(struct syllabus data)
{
	struct nodelist* classnode = (struct nodelist*)malloc(sizeof(struct nodelist));
	classnode->data = data;
	classnode->next = NULL;
	return classnode;
}
int insertnodebytail(struct nodelist* headnodelist, struct syllabus data)
{
	struct nodelist* newnode = creatclassnode(data);
	struct nodelist* tail;
	if (headnodelist->next == NULL)
	{
		tail = headnodelist;
	}
	newnode->next = tail->next;
	tail->next = newnode;
	tail = newnode;
	return 0;
}
int printfweek(int num)
{
	switch (num)
	{
	case 1:printf("����һ\n"); break;
	case 2:printf("���ڶ�\n"); break;
	case 3:printf("������\n"); break;
	case 4:printf("������\n"); break;
	case 5:printf("������\n"); break;
	case 6:printf("������\n"); break;
	case 7:printf("������\n"); break;
	}
	return 0;
}
int openandprintfclassnodelist()
{
	printf("�������ȡ�γ̱��·��:");
	char filename[255];
	scanf("%s", filename);
	FILE* fp;
	if ((fp = fopen(filename, "r+")) == NULL)
	{
		printf("��ȡ�ļ�����\n");
		return 0;
	}
	int a;
	while ((a = fgetc(fp)) != EOF)
	{
		printf("%c", a);
	}
	printf("\n");
	fclose(fp);
	return 0;
}
int freeheadnodelist(struct nodelist* headnodelist)
{
	if (headnodelist->next == NULL)
	{
		free(headnodelist);
		return 0;
	}
	struct nodelist* pf = headnodelist;
	struct nodelist* p = NULL;
	while (pf->next != NULL)
	{
		p = pf->next;
		free(pf);
		pf = p;
	}
	free(pf);
	return 0;
}
int saveweektoclassfile(char* filename, int num)
{
	FILE* fp;
	if ((fp = fopen(filename, "a+")) == NULL)
	{
		printf("�޷������ļ�\n");
		return 0;
	}
	char week[7][5] = { "һ","��","��","��","��","��","��" };
	fprintf(fp, "\n\t\t����%s\n", week[num]);
	filename = NULL;
	fclose(fp);
	return 0;
}
int savaclassfile(char* filename, struct nodelist* headnodelist, int num)
{
	FILE* fp;
	if ((fp = fopen(filename, "a+")) == NULL)
	{
		printf("�����ļ�����\n");
		return 0;
	}
	struct nodelist* p = headnodelist->next;
	if (p == NULL)
	{
		printf("�޷�����\n");
		return 0;
	}
	fprintf(fp, "��%d�� %s��\t", p->data.classnum, p->data.classname);
	if (num % 3 == 0)
	{
		fprintf(fp, "\n");
	}
	filename = NULL;
	fclose(fp);
	freeheadnodelist(headnodelist);
	return 0;
}
int creatandsaveclassnodelist(char* filename)
{
	printf("�������Ͽ�������:");
	int a;
	scanf("%d", &a);
	while (a > 7)
	{
		printf("�����������������:");
		scanf("%d", &a);
	}
	int b;
	for (b = 0; b < a; ++b)
	{
		printfweek(b + 1);
		saveweektoclassfile(filename, b);
		struct syllabus info;
		char week[7][5] = { "һ","��","��","��","��","��","��" };
		printf("����������%s�϶��ٽ�:", week[b]);
		int d, e;
		scanf("%d", &d);
		while (d > 8)
		{
			printf("�����������������:");
			scanf("%d", &d);
		}
		for (e = 0; e < d; ++e)
		{
			struct nodelist* headnodelist = creatclasslist();
			printf("��%d��", e + 1);
			info.classnum = e + 1;
			printf("������γ�����:");
			scanf("%s", info.classname);
			insertnodebytail(headnodelist, info);
			savaclassfile(filename, headnodelist, e + 1);
		}
	}
	filename = NULL;
	return 0;
}
int main()
{
	do
	{
		printf("\t\tc���Կγ̱�\n");
		printf("\t\t1.���ļ���ȡ�γ̱�\n");
		printf("\t\t2.����һ���¿γ̱�\n");
		printf("\t\t3.���������˳�\n");
		printf("\t\t���������ѡ��:");
		int a;
		scanf("%d", &a);
		switch (a)
		{
		case 1:openandprintfclassnodelist(); break;
		case 2:
			printf("�����뱣���ļ�·��:");
			FILE* fp;
			char filename[255];
			scanf("%s", filename);
			if ((fp = fopen(filename, "w+")) == NULL)
			{
				printf("�������\n");
				break;
			}
			fclose(fp);
			creatandsaveclassnodelist(filename); break;
		default:return 0; break;
		}
	} while (1);
}