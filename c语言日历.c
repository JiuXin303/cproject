#include <stdio.h>
#include <math.h>
#include <time.h>
int shengxiao(int year)
{
    switch (year%10)
    {
    case 4:printf("\033[32m甲\033[0m");break;
    case 5:printf("\033[32m乙\033[0m");break;
    case 6:printf("\033[32m丙\033[0m");break;
    case 7:printf("\033[32m丁\033[0m");break;
    case 8:printf("\033[32m戊\033[0m");break;
    case 9:printf("\033[32m己\033[0m");break;
    case 0:printf("\033[32m庚\033[0m");break;
    case 1:printf("\033[32m辛\033[0m");break;
    case 2:printf("\033[32m壬\033[0m");break;
    case 3:printf("\033[32m癸\033[0m");break;
    }
    switch (year-year/12*12)
    {
    case 0:printf("\033[32m申猴年\n\033[0m");break;
    case 1:printf("\033[32m酉鸡年\n\033[0m");break;
    case 2:printf("\033[32m戌狗年\n\033[0m");break;
    case 3:printf("\033[32m亥猪年\n\033[0m");break;
    case 4:printf("\033[32m子鼠年\n\033[0m");break;
    case 5:printf("\033[32m丑牛年\n\033[0m");break;
    case 6:printf("\033[32m寅虎年\n\033[0m");break;
    case 7:printf("\033[32m卯兔年\n\033[0m");break;
    case 8:printf("\033[32m辰龙年\n\033[0m");break;
    case 9:printf("\033[32m巳蛇年\n\033[0m");break;
    case 10:printf("\033[32m午马年\n\033[0m");break;
    case 11:printf("\033[32m未羊年\n\033[0m");break;
    }
    return 0;
}
int xingqi(int y,int m,int d)
{
        int year = y;
        if (m == 1 || m == 2)
        {
                m = m + 12;
                y = y - 1;
        }
        int week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
        switch (week)
        {
        case 0: printf("\033[36m星期一\t\033[0m"); break;
        case 1: printf("\033[36m星期二\t\033[0m"); break;
        case 2: printf("\033[36m星期三\t\033[0m"); break;
        case 3: printf("\033[36m星期四\t\033[0m"); break;
        case 4: printf("\033[36m星期五\t\033[0m"); break;
        case 5: printf("\033[36m星期六\t\033[0m"); break;
        case 6: printf("\033[36m星期日\t\033[0m"); break;
        }
        return 0;
}
int rili(int year,int m)
{
        int a[2][12] =
        {
                {31,29,31,30,31,30,31,31,30,31,30,31},
                {31,28,31,30,31,30,31,31,30,31,30,31}
        };
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 3200 != 0) || year % 172800 == 0)
        {
                printf("\033[32m\t\t%d年%d月 闰年 \033[0m", year, m);
                shengxiao(year);
                int b;
                for (b = 1; b <= a[0][m - 1]; b++)
                {
                        printf("\033[36m%d号:\033[0m",b);
                        xingqi(year,m,b);
                        if(b%3==0)
                        {
                        printf("\n");
                        }
                }
                printf("\n");
                return 0;
    }
        else;
        {
                printf("\033[32m\t\t%d年%d月 平年 \033[0m", year, m);
                shengxiao(year);
                int c;
                for (c = 1; c <= a[1][m - 1]; c++)
                {
                        printf("\033[36m%d号:\033[0m", c);
                        xingqi(year,m,c);
                        if(c%3==0)
                        {
                        printf("\n");
                        }
                }
                printf("\n");
        }
        return 0;
}
int main()
{
        do
        {
        printf("\033[35m\t\tc语言日历\n\033[0m");
        time_t timep;
        struct tm *p;
        time (&timep);
        p=gmtime(&timep);
        int a=1900+p->tm_year;
        int b=1+p->tm_mon;
        int c=p->tm_mday;
        if((p->tm_hour>=16)&&(p->tm_hour<=23))
        {
        c++;
        }
        printf("\033[32m\t\t%d年%d月%d日\n\033[0m",a,b,c);
        printf("\033[35m\t\t1.显示当前年月日历\n\033[0m");
        printf("\033[35m\t\t2.显示某年某月日历\n\033[0m");
        printf("\033[35m\t\t输入其它数字退出\n\033[0m");
        printf("\033[35m\t\t请输入你的选项:\033[0m");
        int d;
        scanf("%d",&d);
        switch (d)
        {
        case 1:
        rili(a,b);
        break;
        case 2:
        printf("");
        int e,f;
        printf("\033[34m请输入年:\033[0m");
        scanf("%d", &e);
        printf("\033[34m请输入月:\033[0m");
        scanf("%d",&f);
        while(f>12)
        {
        printf("\033[31m输入错误,请重新输入:\033[0m");
        scanf("%d",&f);
        }
        rili(e, f);
        break;
        default:
        printf("\033[31m退出中...\n\033[0m");
        return 0;
        break;
        }
        }while(1);
}
