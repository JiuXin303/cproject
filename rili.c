#include <stdio.h> 
#include <time.h>
int main(void)
{	
	printf("c��������\n");
	printf("1.����������������;\n");
	printf("3.���б������������κβ���Ӱ�죬���˸Ų�����;\n");
	printf("4.�κ�δ������ͬ��Ա�������е��޸Ĳ������������������ƽ⡢���ࡢ���ο����ȣ����˸Ų�����;\n") ;
	printf("5.ͬ��������1,��ͬ�����������������˳�;\n");
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
 	printf("1.��ʾ����\n"); 
	printf("2.��������\n");   
	time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);
    printf("%d��%d��%d��\n",1900+p->tm_year,1+p->tm_mon,p->tm_mday);
	printf("3.�������������˳�\n");
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
	printf("c��������\n"); 	
	printf("������1����,���������˳���");
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
	printf("��������ݣ�"); 
	int year;
	scanf("%d",&year);
	if ((year%4==0&&year%100!=0)||(year%400==0&&year%3200!=0)||year%172800==0)
	{
	printf("%d��������\n",year);	
    int b;
	for (b=0;b<13;b++)
	{
    if (b==1)
    {
    printf("1��:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==2) 
	{
	printf("2��:");
	int c;
    for (c=0;c<30;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
    else if (b==3) 
	{
	printf("3��:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==4)
	{
	printf("4��:");
	int c;
    for (c=0;c<31;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==5)
	{
	printf("5��:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==6)
	{
	printf("6��:");
	int c;
    for (c=0;c<31;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==7)
	{
	printf("7��:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==8)
	{
	printf("8��:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==9)
	{
	printf("9��:");
	int c;
    for (c=0;c<31;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==10)
	{
	printf("10��:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==11)
	{
	printf("11��:");
	int c;
    for (c=0;c<31;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if(b==12)
	{
	printf("12��:");
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
	printf("%d����ƽ��\n",year);	
    int b;
	for (b=0;b<13;b++)
	{
    if (b==1)
    {
    printf("1��:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==2) 
	{
	printf("2��:");
	int c;
    for (c=0;c<29;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
    else if (b==3) 
	{
	printf("3��:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==4)
	{
	printf("4��:");
	int c;
    for (c=0;c<31;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==5)
	{
	printf("5��:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==6)
	{
	printf("6��:");
	int c;
    for (c=0;c<31;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==7)
	{
	printf("7��:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==8)
	{
	printf("8��:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==9)
	{
	printf("9��:");
	int c;
    for (c=0;c<31;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==10)
	{
	printf("10��:");
	int c;
    for (c=0;c<32;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if (b==11)
	{
	printf("11��:");
	int c;
    for (c=0;c<31;c++)
    {
    printf("%d ",c);
	}
	printf("\n");
	}
	else if(b==12)
	{
	printf("12��:");
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
	printf("��������\n");
	printf("�����������ꡢ�¡��գ�\n");
	int y,m,d; 
	scanf("%d %d %d",&y,&m,&d);
	printf("%d��%d��%d��\n",y,m,d);
	int n=m;
    if (n==1||n==2)
    {
    m=m+12;
    int y=y-1;
	}
	int Week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	switch(Week)
    {
    case 0: printf("����һ\n"); break;
    case 1: printf("���ڶ�\n"); break;
    case 2: printf("������\n"); break;
    case 3: printf("������\n"); break;
    case 4: printf("������\n"); break;
    case 5: printf("������\n"); break;
    case 6: printf("������\n"); break;
    }
	goto xun;	
	exit:
	printf("�˳���...\n"); 
	return 0; 
	}
