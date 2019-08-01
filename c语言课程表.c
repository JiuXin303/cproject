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
       struct nodelist *next;
};
struct nodelist *creatclasslist()
{
       struct nodelist *classlist=(struct nodelist *)malloc(sizeof(struct nodelist));
       classlist->next=NULL;
       return classlist;
}
struct nodelist *creatclassnode(struct syllabus data)
{
       struct nodelist *classnode=(struct nodelist *)malloc(sizeof(struct nodelist));
       classnode->data=data;
       classnode->next=NULL;
       return classnode;
}
int insertnodebytail(struct nodelist *headnodelist,struct syllabus data)
{
    struct nodelist *newnode=creatclassnode(data);
    struct nodelist *tail;
    if (headnodelist->next==NULL)
    {
     tail=headnodelist;
    }
    newnode->next=tail->next;
    tail->next=newnode;
    tail=newnode;
    free(newnode);
    return 0;
}
int printfweek (int num)
{
    switch(num)
    {
     case 1:printf("星期一\n");break;
     case 2:printf("星期二\n");break;
     case 3:printf("星期三\n");break;
     case 4:printf("星期四\n");break;
     case 5:printf("星期五\n");break;
     case 6:printf("星期六\n");break;
     case 7:printf("星期日\n");break;
    }
    return 0;
}
int openandprintfclassnodelist()
{
    printf("请输入读取课程表的路径:");
    char filename[255];
    scanf("%s",filename);
    FILE *fp;
    if ((fp=fopen(filename,"r+"))==NULL)
    {
     printf("读取文件错误\n");
     return 0;
    }
    int a;
    while((a=fgetc(fp))!=EOF)
    {
     printf("%c",a);
    }
    printf("\n");
    fclose(fp);
    return 0;
}
int freeheadnodelist(struct nodelist *headnodelist)
{
    if(headnodelist->next==NULL)
    {
     free(headnodelist);
     return 0;
    }
    struct nodelist *pf=headnodelist;
    struct nodelist *p=pf->next;
    while (pf->next!=NULL)
    {
     p=pf->next;
     free(pf);
     pf=p;
    }
    free(pf);
    free(headnodelist);
    return 0;
}
int saveweektoclassfile(char *filename,int num)
{
    FILE *fp;
    printf("请输入要保存的文件路径:");
    if ((fp=fopen(filename,"a+"))==NULL)
    {
     printf("无法保存文件\n");
     return 0;
    }
    fprintf(fp,"\n星期%d\n",num);
    filename=NULL;
    fclose(fp);
    return 0;
}
int savaclassfile(char *filename,struct nodelist *headnodelist,int num)
{
    FILE *fp;
    if ((fp=fopen(filename,"a+"))==NULL)
    {
     printf("保存文件错误\n");
     return 0;
    }
    struct nodelist *p=headnodelist->next;
    if (p==NULL)
    {
     printf("无法保存\n");
     return 0;
    }
    fprintf(fp,"第%d节 %s课\t",p->data.classnum,p->data.classname);
    if (num%3==0)
    {
     fprintf(fp,"\n");
    }
    filename=NULL;
    fclose(fp);
    free(headnodelist);
    return 0;
}
int creatandsaveclassnodelist(char *filename)
{
    printf("请输入上课总天数:");
    int a;
    scanf("%d",&a);
    while(a>7)
    {
     printf("输入错误，请重新输入:");
     scanf("%d",&a);
    }
    int b;
    for (b=0;b<a;++b)
    {
     int c=b+1;
     printfweek(c);
     saveweektoclassfile(filename,c);
     struct syllabus info;
     printf("请输入星期%d上多少节:",c);
     int d,e;
     scanf("%d",&d);
     for (e=0;e<d;++e)
     {
      struct nodelist *headnodelist=creatclasslist();
      printf("第%d节",e+1);
      info.classnum=e+1;
      printf("请输入课程名字:");
      scanf("%s",info.classname);
      insertnodebytail(headnodelist,info);
      savaclassfile(filename,headnodelist,e+1);
     }
    }
    filename=NULL;
    return 0;
}
int main()
{
    do
    {
     printf("\t\tc语言课程表\n");
     printf("\t\t1.从文件读取课程表\n");
     printf("\t\t2.创建一个新课程表\n");
     printf("\t\t3.其他数字退出\n");
     printf("\t\t请输入你的选项:");
     int a;
     scanf("%d",&a);
     switch (a)
     {
      case 1:openandprintfclassnodelist();break;
      case 2:
      printf("请输入保存文件路径:");
      FILE *fp;
      char filename[255];
      scanf("%s",filename);
      if ((fp=fopen(filename,"w+"))==NULL)
      {
       printf("保存错误\n");
       break;
      }
      fclose(fp);
      creatandsaveclassnodelist(filename);break;
      default:return 0;break;
     }
    }while(1);
}
