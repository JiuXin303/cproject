#include <stdio.h>
#include <math.h>
int pt()
{
    printf("\033[40;35m\tc语言计算器\n\033[0m");
    printf("\033[40;35m\t1.加法运算\n\033[0m");
    printf("\033[40;35m\t2.减法运算\n\033[0m");
    printf("\033[40;35m\t3.乘法运算\n\033[0m");
    printf("\033[40;35m\t4.除法运算\n\033[0m");
    printf("\033[40;35m\t5.余数运算\n\033[0m");
    printf("\033[40;35m\t6.平方运算\n\033[0m");
    printf("\033[40;35m\t7.开方运算\n\033[0m");
    printf("\033[40;35m\t其它数字退出\n\033[0m");
    printf("\033[40;35m\t请输入你的选项:\033[0m");
    int a=0;
    scanf("%d",&a);
    return (a);
}
int main()
{
    double a,b;
    do
      {
       int ch=pt();
       switch(ch)
       {
       case 1:
       printf("\033[40;34m请输入两个数做加法运算:\n\033[0m");
       scanf("%lf%lf",&a,&b);
       printf("\033[40;33m%lf + %lf=%lf\n\033[0m",a,b,a+b);
       break;
       case 2:
       printf("\033[40;34m请输入两个数做减法运算:\n\033[0m");
       scanf("%lf%lf",&a,&b);
       printf("\033[40;33m%lf – %lf=%lf\n\033[0m",a,b,a-b);
       break;
       case 3:
       printf("\033[40;34m请输入两个数做乘法运算:\n\033[0m");
       scanf("%lf%lf",&a,&b);
       printf("\033[40;33m%lf × %lf=%lf\n\033[0m",a,b,a*b);
       break;
       case 4:
       printf("\033[40;34m请输入两个数做除法运算:\n\033[0m");
       scanf("%lf%lf",&a,&b);
       printf("\033[40;33m%lf ÷ %lf=%lf\n\033[0m",a,b,a/b);
       break;
       case 5:
       printf("\033[40;34m请输入两个数做余数运算:\n\033[0m");
       scanf("%lf%lf",&a,&b);
       printf("\033[40;33m%lf ≡ %lf=%lf\n\033[0m",a,b,fmod(a,b));
       break;
       case 6:
       printf("\033[40;34m请输入两个数做平方运算:\n\033[0m");
       scanf("%lf%lf",&a,&b);
       printf("\033[40;33m%lf的%lf平方为%lf\n\033[0m",a,b,pow(a,b));
       break;
       case 7:
       printf("\033[40;34m请输入两个数做开方运算:\n\033[0m");
       scanf("%lf%lf",&a,&b);
       printf("\033[40;34m%lf的%lf开方为%lf\n\033[0m",a,b,pow(a,1/b));
       break;
       default:
       printf("\033[40;31m退出中...\n\033[0m");
       goto et;
       break;
       }
      }
      while(1);
      et:
      return 0;
}
