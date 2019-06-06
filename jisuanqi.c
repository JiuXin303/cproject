#include <stdio.h>
#include <math.h>
int main()
{
        printf("c语言计算器说明:\n");
	printf("1.本计算器由懒人制作;\n");
	printf("2.本计算器支持小数点计算;\n");
	printf("3.运行本程序如果造成任何不良影响，本人概不负责;\n");
        printf("4.任何未经作者同意对本程序进行的修改操作，包含但不限于破解、反编、二次开发等，造成任何不良影响，本人概不负责;\n") ;
	printf("同意请输入1,不同意请输入其它数字退出:");
    int what;
    scanf("%d",&what); 
    if (what==1)
    {
	goto xunhuan;
    }
	else;
    {
	printf("退出中...\n"); 
	} 
	return 0;
	xunhuan:
	printf("c语言计算器\n");
	printf("\n"); 
    printf("1.做两个数的加法运算\n");
    printf("\n"); 
    printf("2.做两个数的减法运算\n");
    printf("\n"); 
    printf("3.做两个数的乘法运算\n");
    printf("\n"); 
    printf("4.做两个数的除法运算\n");
    printf("\n"); 
    printf("5.做两个数的余数运算\n");
    printf("\n"); 
    printf("6.输入其它数字则退出\n");
    printf("\n"); 
    printf("请选择你的选项\n");
    float shu;
    scanf("%f",&shu);
    if (shu==1)
    {
    printf("请输入两个数做加法运算\n");
    double a,b;
    scanf("%lf%lf",&a,&b);
    double c=a+b;
    printf("%lf + %lf=%lf\n",a,b,c);
    goto xunhuan;
    }
    else if(shu==2)
    {
    printf("请输入两个数做减法运算\n");
    double d,e;
    scanf("%lf%lf",&d,&e);
    double f=d-e;
    printf("%lf – %lf=%lf\n",d,e,f);
    goto xunhuan;
    }
    else if(shu==3)
   {
    printf("请输入两个数做乘法运算\n");
    double h,i;
    scanf("%lf%lf",&h,&i);
    double j=h*i;
    printf("%lf × %lf=%lf\n",h,i,j);
    goto xunhuan;
    }
    else if(shu==4)
    {
    printf("请输入两个数做除法运算\n");
    double k,l;
    scanf("%lf%lf",&k,&l);
    double n=k/l;
    printf("%lf ÷ %lf=%lf\n",k,l,n);
    goto xunhuan;
    }
    else if(shu==5)
    {
    printf("请输入两个数做余数运算\n");
    double m,o;
    scanf("%lf%lf",&m,&o); 
    printf("%lf ≡ %lf=%lf\n",m,o,fmod(m,o));
    goto xunhuan;
    }
    else;
    {
    printf("退出中...\n");
    }
    return 0; 
 }

