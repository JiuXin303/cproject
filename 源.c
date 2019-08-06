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
		printf("无法创建\n");
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
	printf("请输入路径:");
	scanf("%s", filename);
	FILE* fp;
	if ((fp = fopen(filename, "w+")) == NULL)
	{
		printf("无法创建\n");
		return 0;
	}
	printf("创建成功\n");
	fclose(fp);
	addcreatnewtextcontent(filename);
	return 1;
}

int loadtext(struct headnode* headnode, char* filename)
{
	FILE* fp;
	if ((fp = fopen(filename, "r+")) == NULL)
	{
		printf("无法打开文件\n");
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
		printf("无法显示\n");
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
	printf("请输入要删除的行数:");
	int a;
	scanf("%d", &a);
	struct headnode* p = headnode;
	if (p == NULL)
	{
		printf("无法删除\n");
		return 0;
	}
	while (p->data.num != a)
	{
		pf = p;
		p = p->next;
		if (p == NULL)
		{
			printf("无法删除\n");
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
	printf("请输入插入的行数:");
	int a;
	scanf("%d", &a);
	printf("请输入插入的内容:");
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
			printf("无法插入,输入行数大于所有行数\n");
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
		printf("无法保存\n");
		return 0;
	}
	struct headnode* p = headnode;
	if (p->next == NULL)
	{
		printf("无法保存\n");
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
		printf("读取文件错误\n");
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
	printf("\t\t1.显示行数\n");
	printf("\t\t2.删除某行\n");
	printf("\t\t3.插入某行\n");
	printf("\t\t4.保存文件\n");
	printf("\t\t输入其它数字退出\n");
	printf("\t\t请输入你的选项:");
	int a;
	scanf("%d", &a);
	return a;
}

int editortext()
{
	struct headnode* headnode = creatheadnode();
	printf("请输入编辑文件路径:");
	char filename[255];
	scanf("%s", filename);
	loadtext(headnode, filename);
	while (1)
	{
		printf("文本内容:\n");
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
	printf("\t\tC语言文本操作\n");
	printf("\t\t说明:1.编辑文本默认在文本末尾加一行,如果第一行存在可删除\n");
	printf("\t\t说明:2.保存错误随便插入一行即可\n");
	printf("\t\t1.创建文本\n");
	printf("\t\t2.编辑文本\n");
	printf("\t\t3.删除文本\n");
	printf("\t\t输入其它数字退出\n");
	printf("\t\t请输入你的选项:");
	int a;
	scanf("%d", &a);
	return a;
}

int deletetextfile()
{
	printf("请输入要删除的文本:");
	char name[255];
	scanf("%s", name);
	if ((remove(name)) == -1)
	{
		printf("删除文本失败\n");
		return 0;
	}
	printf("已删除文本:%s\n", name);
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