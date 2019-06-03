#include <stdio.h> 
#include <time.h>
int main(void)
{	
	printf("c语言日历\n");
	printf("1.本日历由懒人制作;\n");
	printf("3.运行本程序如果造成任何不良影响，本人概不负责;\n");
	printf("4.任何未经作者同意对本程序进行的修改操作，包含但不限于破解、反编、二次开发等，本人概不负责;\n") ;
	printf("5.同意请输入1,不同意请输入任意内容退出;\n");
	int lan;
	scanf ("%d",&lan);
    if (lan==1)
    {
    goto xun;
	}
	else;
	{
	goto exit;
	}
	xun:
 	printf("1.显示日历\n"); 
	printf("2.计算星期\n");   
	time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);
    printf("%d年%d月%d日\n",1900+p->tm_year,1+p->tm_mon,p->tm_mday);
	printf("3.输入任意内容退出\n");
	int xun;
	scanf("%d",&xun);
    if (xun==1)
    {
    goto xunhuanrili;
	}
	else if (xun==2)
	{
	goto xingqi;
	}
	else;
	{
	goto exit;
	}
	xunhuanrili:	
	printf("c语言日历\n"); 	
	printf("请输入1继续,输入其它退出：");
	int shu;
	scanf("%d",&shu);
	if (shu==1)
	{
	goto rili;
	}
	else;
	{
	goto exit;
	}
	rili: 
	printf("请输入年份："); 
	int year;
	scanf("%d",&year);
	if ((year%4==0&&year%100!=0)||(year%400==0&&year%3200!=0)||year%172800==0)
	{
	printf("%d年是闰年\n",year);	
    int b;
	for (b=0;b<13;b++)
	{
    if (b==1)
    {
    printf("1月:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==2) 
	{
	printf("2月:");
	int c;
    for (c=0;c<30;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
    else if (b==3) 
	{
	printf("3月:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==4)
	{
	printf("4月:");
	int c;
    for (c=0;c<31;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==5)
	{
	printf("5月:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==6)
	{
	printf("6月:");
	int c;
    for (c=0;c<31;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==7)
	{
	printf("7月:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==8)
	{
	printf("8月:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==9)
	{
	printf("9月:");
	int c;
    for (c=0;c<31;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==10)
	{
	printf("10月:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==11)
	{
	printf("11月:");
	int c;
    for (c=0;c<31;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if(b==12)
	{
	printf("12月:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	}
	goto xun;
    }
	else;
    {
	printf("%d年是平年\n",year);	
    int b;
	for (b=0;b<13;b++)
	{
    if (b==1)
    {
    printf("1月:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==2) 
	{
	printf("2月:");
	int c;
    for (c=0;c<29;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
    else if (b==3) 
	{
	printf("3月:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==4)
	{
	printf("4月:");
	int c;
    for (c=0;c<31;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==5)
	{
	printf("5月:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==6)
	{
	printf("6月:");
	int c;
    for (c=0;c<31;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==7)
	{
	printf("7月:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==8)
	{
	printf("8月:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==9)
	{
	printf("9月:");
	int c;
    for (c=0;c<31;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==10)
	{
	printf("10月:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==11)
	{
	printf("11月:");
	int c;
    for (c=0;c<31;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if(b==12)
	{
	printf("12月:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	}
	goto xun;
    }
	xingqi:
	printf("计算星期\n");
	printf("请依次输入年、月、日：\n");
	int y,m,d; 
	scanf("%d %d %d",&y,&m,&d);
	printf("%d年%d月%d日\n",y,m,d);
	int n=m;
    if (n==1||n==2)
    {
    m=m+12;
    int y=y-1;
	}
	int Week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	switch(Week)
    {
    case 0: printf("星期一\n"); break;
    case 1: printf("星期二\n"); break;
    case 2: printf("星期三\n"); break;
    case 3: printf("星期四\n"); break;
    case 4: printf("星期五\n"); break;
    case 5: printf("星期六\n"); break;
    case 6: printf("星期日\n"); break;
    }
	goto xun;	
	exit:
	printf("退出中...\n"); 
	return 0; 
	}
