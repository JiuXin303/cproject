#include <stdio.h>
#include <math.h>
int pt()
{
        printf("\033[35m\t\tc语言计算器\n\033[0m");
        printf("\033[35m\t\t1.加法运算\n\033[0m");
        printf("\033[35m\t\t2.减法运算\n\033[0m");
        printf("\033[35m\t\t3.乘法运算\n\033[0m");
        printf("\033[35m\t\t4.除法运算\n\033[0m");
        printf("\033[35m\t\t5.余数运算\n\033[0m");
        printf("\033[35m\t\t6.平方运算\n\033[0m");
        printf("\033[35m\t\t7.开方运算\n\033[0m");
        printf("\033[35m\t\t其它数字退出\n\033[0m");
        printf("\033[35m\t\t请输入你的选项:\033[0m");
        int a = 0;
        scanf("%d", &a);
        return (a);
}
int main()
{
        do
        {
        double a, b;
                int ch = pt();
                switch (ch)
                {
                case 1:
                        printf("\033[34m请输入两个数做加法运算:\n\033[0m");
                        scanf("%lf%lf", &a, &b);
                        printf("\033[33m%lf + %lf=%lf\n\033[0m", a, b, a + b);
                        break;
                case 2:
                        printf("\033[34m请输入两个数做减法运算:\n\033[0m");
                        scanf("%lf%lf", &a, &b);
                        printf("\033[33m%lf – %lf=%lf\n\033[0m", a, b, a - b);
                        break;
                case 3:
                        printf("\033[34m请输入两个数做乘法运算:\n\033[0m");
                        scanf("%lf%lf", &a, &b);
                        printf("\033[33m%lf × %lf=%lf\n\033[0m", a, b, a * b);
                        break;
                case 4:
                        printf("\033[34m请输入两个数做除法运算:\n\033[0m");
                        scanf("%lf%lf", &a, &b);
                        printf("\033[33m%lf ÷ %lf=%lf\n\033[0m", a, b, a / b);
                        break;
                case 5:
                        printf("\033[34m请输入两个数做余数运算:\n\033[0m");
                        scanf("%lf%lf", &a, &b);
                        printf("\033[33m%lf ≡ %lf=%lf\n\033[0m", a, b, fmod(a, b));
                        break;
                case 6:
                        printf("\033[34m请输入两个数做平方运算:\n\033[0m");
                        scanf("%lf%lf", &a, &b);
                        printf("\033[34m%lf的%lf平方为%lf\n\033[0m", a, b, pow(a, b));
                        break;
                case 7:
                        printf("\033[34m请输入两个数做开方运算:\n\033[0m");
                        scanf("%lf%lf", &a, &b);
                        printf("\033[34m%lf的%lf开方为%lf\n\033[0m", a, b, pow(a, 1 / b));
                        break;
                default:
                        printf("\033[31m退出中...\n\033[0m");
                        return 0;
                        break;
                }
        } while (1);
}
