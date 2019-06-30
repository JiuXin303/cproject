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
	case 0: printf("星期一 "); break;
	case 1: printf("星期二 "); break;
	case 2: printf("星期三 "); break;
	case 3: printf("星期四 "); break;
	case 4: printf("星期五 "); break;
	case 5: printf("星期六 "); break;
	case 6: printf("星期日 "); break;
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
		printf("%d是闰年\n", year);
		printf("%d月:\n", m);
		int b;
		for (b=1;b<=a[0][m - 1];b++)
		{
			printf("%d", b);
			xingqi(year, m, b);
		}
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
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	rili(a, b);
	return 0;
}