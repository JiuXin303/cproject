#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
    printf("c文件操作程序说明:\n");
    printf("1.本文件操作程序由懒人制作;\n");
    printf("2.本文件操作程序支持文件:创建、复制、删除、查看、重命名操作;\n");
    printf("4.本文件操作程序中复制对文本有用，对于文件请勿使用;\n");
    printf("3.本文件操作程序进入文件路径看文件请一级一级的进路径来查看;\n");
    printf("5.本文件操作程序输入路径用完整路径或当前路径这两种,完整用/来表示路径，当前路径直接输入就行;\n");
    printf("6.运行本程序如果造成任何不良影响，本人概不负责;\n");
    printf("7.任何未经作者同意对本程序进行的修改操作，包含但不限于破解、反编、二次开发等，造成任何不良影响，本人概不负责;\n") ;
    printf("同意请输入1,不同意请输入其它数字退出:");
    int xianyi;
    scanf("%d",&xianyi);
    if (xianyi==1)
    {
    goto zhu;
    }
    else;
    {
     printf("退出中...\n"); 
     goto et;
    }
    zhu:
    printf("0.当前文件\n");
    printf("1.进入文件\n");
    printf("2.创建项目\n");
    printf("3.删除文件\n");
    printf("4.文件列表\n");
    printf("5.复制文件\n");
    printf("6.重命名文件:\n");
    printf("7.文件类型查看:\n");
    printf("输入其他数字退出\n");
    printf("请输入你的选项:");
    int a;
    scanf("%d",&a);
    switch(a)
    {
    case 0: printf("当前目录:");goto dq;break;
    case 1: printf("进入目录:");goto cd;break;
    case 2: printf("创建项目\n");goto mk;break;
    case 3: printf("删除文件\n");goto dl;break;
    case 4: printf("文件列表:\n");goto lt;break;
    case 5: printf("复制文件\n");goto cp;break;
    case 6: printf("重命名文件\n");goto cm;break;
    case 7: printf("文件类型如下:\n");goto type;break;
    default: printf("退出中...\n");goto et;break;
    }
    dq:
    printf("");
    char *pf = NULL;
    pf = getcwd(NULL,0);
    puts(pf);
    goto zhu;
    cd:
    printf("");
    char *cd=NULL;
    cd=(char *)malloc(sizeof(char));
    scanf("%s",cd);
    chdir(cd);
    free(cd);
    goto zhu;
    mk:
    printf("1.创建文件夹\n");
    printf("2.创建文本文件\n");
    printf("3.输入任意数字返回主菜单\n");
    printf("请输入你的选项:");
    int mk;
    scanf("%d",&mk);
    if (mk==1)
    {
    char mkname[255];
    printf("请输入你要创建的文件夹:");
    scanf("%s", mkname);
    mkdir(mkname,0777);
    printf("创建文件夹:%s........成功\n",mkname);
    goto mk;
    }
    if (mk==2)
    {
    FILE *fp;
    char mknames[255];
    printf("请输入你要创建的文本，不用输入.txt:");
    scanf("%s", mknames);
    strcat(mknames, ".txt");
    fp=fopen(mknames, "wt+");
    printf("创建文本:%s........成功\n",mknames);
    fclose(fp);
    goto mk;
    }
    else;
    {
    goto zhu;
    }
    dl:
    printf("");
    char dlname[255];
    printf("请输入你要删除的文件:");
    scanf("%s",dlname);
    remove(dlname);
    printf("删除文件:%s........成功\n",dlname);
    goto zhu;
    lt:
    printf("");
    DIR *dp=NULL;
    struct dirent *dirp;
    dp= opendir(".");
    while ((dirp = readdir(dp)) != NULL) 
          {
          if (strcmp(dirp->d_name,".") == 0 || strcmp(dirp->d_name,"..") == 0)
          {
          continue;
          }
          printf("文件名:%s ", dirp->d_name );
          printf("文件类型:%d\n",dirp->d_type);
          }
          closedir(dp);
          goto zhu;
    cp:
    printf("");
    char cp;
    char oname[255];
    printf("请输入要复制文件的路径:");
    scanf("%s",oname);
    char nname[255];
    printf("请输入复制后的文件路径:");
    scanf("%s",nname);
    FILE *odname=fopen(oname,"rb+");
    FILE *nwname=fopen(nname,"wb+");
    while ((cp=fgetc(odname))!=EOF)
    {
    fputc(cp,nwname);
    }
    printf("文件:%s复制到:%s........成功",oname,nname);
    fclose(odname);
    fclose(nwname);
    odname = NULL;
    nwname = NULL;
    goto zhu;
    cm:
    printf("");
    char oldname[255];
    printf("请输入要重命名的文件路径:");
    scanf("%s",oldname);
    char newname[255];
    printf("请输入重命名后文件的路径:");
    scanf("%s",newname);
    rename(oldname,newname);
    printf("文件:%s 重命名为:%s........成功\n", oldname, newname);
    goto zhu;
    type:
    printf("0是未知\n");
    printf("1是管道\n");
    printf("2是字符特殊文件\n");
    printf("4是目录文件\n");
    printf("6是块特殊文件\n");
    printf("8是普通文件\n");
    printf("10是符号连接\n");
    printf("12是套接字\n");
    printf("14是映射文件\n");
    goto zhu;
    et:
    return 0;
}
