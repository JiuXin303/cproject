#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct line
{
	int num;
	char text[100];
};

struct headnode
{
	struct line data;
	struct headnode* next;
};

struct headnode* creatheadnode(void)
{
	struct headnode* newnodelist = (struct headnode*)malloc(sizeof(struct headnode));
	newnodelist->next = NULL;
	return newnodelist;
}

struct headnode* creatsubnoed(struct line data)
{
	struct headnode* subnode = (struct headnode*)malloc(sizeof(struct headnode));
	subnode->data = data;
	subnode->next = NULL;
	return subnode;
}
struct headnode* tail;
int insertnodebytail(struct headnode* headnode, struct line data)
{
	struct headnode* newnodedata = creatsubnoed(data);
	if (headnode->next == NULL)
	{
		tail = headnode;
	}
	newnodedata->next = tail->next;
	tail->next = newnodedata;
	tail = newnodedata;
	return 0;
}

int freeheadnode(struct headnode* headnode)
{
	if (headnode->next == NULL)
	{
		free(headnode);
		return 0;
	}
	struct headnode* pf = headnode;
	struct headnode* p = NULL;
	while (pf->next != NULL)
	{
		p = pf->next;
		free(pf);
		pf = p;
	}
	free(p);
	return 1;
}
int addcreatnewtextcontent(char* filename)
{
	FILE* fp;
	if ((fp = fopen(filename, "r+")) == NULL)
	{
		printf("�޷�����\n");
		remove(filename);
		return 0;
	}
	fprintf(fp, "\n");
	fclose(fp);
	return 0;
}
int creattext(void)
{
	char filename[255];
	printf("������·��:");
	scanf("%s", filename);
	FILE* fp;
	if ((fp = fopen(filename, "w+")) == NULL)
	{
		printf("�޷�����\n");
		return 0;
	}
	printf("�����ɹ�\n");
	fclose(fp);
	addcreatnewtextcontent(filename);
	return 1;
}

int loadtext(struct headnode* headnode, char* filename)
{
	FILE* fp;
	if ((fp = fopen(filename, "r+")) == NULL)
	{
		printf("�޷����ļ�\n");
		return 0;
	}
	int a = 0;
	struct line t;
	do
	{

		++a;
		t.num = a;
		fgets(t.text, 100, fp);
		insertnodebytail(headnode, t);
	} while (!feof(fp));
	fclose(fp);
	return 1;
}

int printftext(struct headnode* headnode)
{
	struct headnode* p = headnode->next;
	if (p == NULL)
	{
		printf("�޷���ʾ\n");
		return 0;
	}
	while (p->next != NULL)
	{
		printf("%d:%s", p->data.num, p->data.text);
		p = p->next;
	}
	return 0;
}
struct headnode* pf;
int deletetext(struct headnode* headnode)
{
	printf("������Ҫɾ��������:");
	int a;
	scanf("%d", &a);
	struct headnode* p = headnode;
	if (p == NULL)
	{
		printf("�޷�ɾ��\n");
		return 0;
	}
	while (p->data.num != a)
	{
		pf = p;
		p = p->next;
		if (p == NULL)
		{
			printf("�޷�ɾ��\n");
			return 0;
		}
	}
	pf->next = p->next;
	free(p);
	p = NULL;
	struct headnode* num = headnode;
	int b = 0;
	while (num->next != NULL)
	{
		++b;
		num = num->next;
		num->data.num = b;
	}
	return 1;
}

int inserttext(struct headnode* headnode)
{
	printf("��������������:");
	int a;
	scanf("%d", &a);
	printf("��������������:");
	struct line info;
	info.num = a,
		scanf("%s", info.text);
	strcat(info.text, "\n");
	struct headnode* p = headnode;
	struct headnode* content = creatsubnoed(info);
	while (p->data.num != a)
	{
		p = p->next;
		if (p->next == NULL)
		{
			printf("�޷�����,��������������������\n");
			return 0;
		}
	}
	content->next = p->next;
	p->next = content;
	while (content->next != NULL)
	{
		content->data.num = content->data.num + 1;
		content = content->next;
	}
	return 0;
}

int savetext(struct headnode* headnode, char* filename)
{
	FILE* fp;
	if ((fp = fopen(filename, "r+")) == NULL)
	{
		printf("�޷�����\n");
		return 0;
	}
	struct headnode* p = headnode;
	if (p->next == NULL)
	{
		printf("�޷�����\n");
		fclose(fp);
		return 0;
	}
	while (p->next != NULL)
	{
		p = p->next;
		fprintf(fp, "%s", p->data.text);
	}
	fclose(fp);
	return 0;
}

int openandprintffile(char* filename)
{
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

int editortext_menu()
{
	printf("\t\t1.��ʾ����\n");
	printf("\t\t2.ɾ��ĳ��\n");
	printf("\t\t3.����ĳ��\n");
	printf("\t\t4.�����ļ�\n");
	printf("\t\t�������������˳�\n");
	printf("\t\t���������ѡ��:");
	int a;
	scanf("%d", &a);
	return a;
}

int editortext()
{
	struct headnode* headnode = creatheadnode();
	printf("������༭�ļ�·��:");
	char filename[255];
	scanf("%s", filename);
	loadtext(headnode, filename);
	while (1)
	{
		printf("�ı�����:\n");
		openandprintffile(filename);
		int choice = editortext_menu();
		switch (choice)
		{
		case 1:printftext(headnode); break;
		case 2:deletetext(headnode); break;
		case 3:inserttext(headnode); break;
		case 4:savetext(headnode, filename); break;
		default:freeheadnode(headnode); return 0; break;
		}
	}
}

int print_main(void)
{
	printf("\t\tC�����ı�����\n");
	printf("\t\t˵��:1.�༭�ı�Ĭ�����ı�ĩβ��һ��,�����һ�д��ڿ�ɾ��\n");
	printf("\t\t˵��:2.�������������һ�м���\n");
	printf("\t\t1.�����ı�\n");
	printf("\t\t2.�༭�ı�\n");
	printf("\t\t3.ɾ���ı�\n");
	printf("\t\t�������������˳�\n");
	printf("\t\t���������ѡ��:");
	int a;
	scanf("%d", &a);
	return a;
}

int deletetextfile()
{
	printf("������Ҫɾ�����ı�:");
	char name[255];
	scanf("%s", name);
	if ((remove(name)) == -1)
	{
		printf("ɾ���ı�ʧ��\n");
		return 0;
	}
	printf("��ɾ���ı�:%s\n", name);
	return 1;
}

int main(void)
{
	while (1)
	{

		int choice = print_main();
		switch (choice)
		{
		case 1:creattext(); break;
		case 2:editortext(); break;
		case 3:deletetextfile(); break;
		default: return 0; break;
		}
	}
}