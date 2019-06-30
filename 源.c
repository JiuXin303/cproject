#include <stdio.h>
#include <math.h>
#include <time.h>
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
        case 0: printf("星期一\t "); break;
        case 1: printf("星期二\t "); break;
        case 2: printf("星期三\t "); break;
        case 3: printf("星期四\t "); break;
        case 4: printf("星期五\t "); break;
        case 5: printf("星期六\t "); break;
        case 6: printf("星期日\t "); break;
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
                printf("\t\t%d年%d月 闰年\n", year, m);
                int b;
                for (b = 1; b <= a[0][m - 1]; b++)
                {
                        printf("%d号:", b);
                        xingqi(year, m, b);
                }
                printf("\n");
                return 0;
    }
        else;
        {
                printf("\t\t%d年%d月 平年\n", year, m);
                int c;
                for (c = 1; c <= a[1][m - 1]; c++)
                {
                        printf("%d号:", c);
                        xingqi(year, m, c);
                }
                printf("\n");
                return 0;
        }
        return 0;
}
int main()
{
        printf("\t\tc语言日历\n");
        time_t timep;
        struct tm *p;
        time (&timep);
        p=gmtime(&timep);
        printf("\t\t%d年%d月%d日\n",1900+p->tm_year,1+p->tm_mon,p->tm_mday);
main:
        printf("");
        int a, b;
        printf("请输入年:");
        scanf("%d", &a);
        printf("请输入月:");
        scanf("%d",&b);
        while(b>12)
        {
        printf("输入错误,请重新输入:");
        scanf("%d",&b);
        }
        rili(a, b);
        printf("\t\t1.继续\n");
        printf("\t\t其它数字退出\n");
        printf("\t\t请输入你的选项:");
        int c;
        scanf("%d",&c);
        switch (c)
        {
        case 1:goto main;break;
        default:goto exit;break;
        }
exit:
        return 0;
}
