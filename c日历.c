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
	printf("���������:");
	int year=0;
	scanf("%d", &year);
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 3200 != 0) || year % 172800 == 0)
	{
		printf("%d������\n", year);
		int b;
		for (b = 1; b <= 12; b++)
		{
			printf("%d��:", b);
			printf("%d�� ", a[0][b - 1]);
		}
		printf("\n");
		return 0;
	}
	else;
	{
	printf("%d��ƽ��\n", year);
	int c;
	for (c = 1; c <= 12; c++)
	{
		printf("%d��:", c);
		printf("%d�� ", a[1][c - 1]);
	}
	    printf("\n");
	}
	return 0;
}
int xingqi(void)
{
	int y, m, d;
	printf("����������\n");
	printf("��:");
;   scanf("%d", &y);
    printf("��:");
	scanf("%d", &m);
	printf("��:");
	scanf("%d", &d);
	printf("%d��%d��%d����:", y, m, d);
	if (m == 1 || m == 2)
	{
		m = m + 12;
		y = y - 1;
	}
	int week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
	switch (week)
	{
    case 0: printf("����һ\n"); break;
    case 1: printf("���ڶ�\n"); break;
    case 2: printf("������\n"); break;
    case 3: printf("������\n"); break;
    case 4: printf("������\n"); break;
    case 5: printf("������\n"); break;
    case 6: printf("������\n"); break;
	}
	return 0;
}
int main(void)
{
	do
	{
		printf("c��������\n");
		printf("1.����\n");
		printf("2.����\n");
		printf("���������˳�\n");
		printf("���������ѡ��:");
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