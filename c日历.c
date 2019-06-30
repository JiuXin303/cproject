#include <stdio.h>
#include <math.h>
#include <time.h>
int rili(void)
{
    int a[2][12] =
	{
		{31,29,31,30,31,30,31,31,30,31,30,31},
		{31,28,31,30,31,30,31,31,30,31,30,31}
	};
	printf("请输入年份:");
	int year=0;
	scanf("%d", &year);
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 3200 != 0) || year % 172800 == 0)
	{
		printf("%d是闰年\n", year);
		int b;
		for (b = 1; b <= 12; b++)
		{
			printf("%d月:", b);
			printf("%d天 ", a[0][b - 1]);
		}
		printf("\n");
		return 0;
	}
	else;
	{
	printf("%d是平年\n", year);
	int c;
	for (c = 1; c <= 12; c++)
	{
		printf("%d月:", c);
		printf("%d天 ", a[1][c - 1]);
	}
	    printf("\n");
	}
	return 0;
}
int xingqi(void)
{
	int y, m, d;
	printf("请依次输入\n");
	printf("年:");
;   scanf("%d", &y);
    printf("月:");
	scanf("%d", &m);
	printf("日:");
	scanf("%d", &d);
	printf("%d年%d月%d日是:", y, m, d);
	if (m == 1 || m == 2)
	{
		m = m + 12;
		y = y - 1;
	}
	int week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
	switch (week)
	{
    case 0: printf("星期一\n"); break;
    case 1: printf("星期二\n"); break;
    case 2: printf("星期三\n"); break;
    case 3: printf("星期四\n"); break;
    case 4: printf("星期五\n"); break;
    case 5: printf("星期六\n"); break;
    case 6: printf("星期日\n"); break;
	}
	return 0;
}
int main(void)
{
	do
	{
		printf("c语言日历\n");
		printf("1.日历\n");
		printf("2.星期\n");
		printf("其它数字退出\n");
		printf("请输入你的选项:");
		int a;
		scanf("%d", &a);
		switch (a)
		{
		case 1:rili(); break;
		case 2:xingqi(); break;
		default:goto et; break;
		}
	} while (1);
et:
	return 0;
}