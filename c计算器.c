#include <stdio.h>
#include <math.h>
int pt()
{
	printf("\033[40;35m\tc���Լ�����\n\033[0m");
	printf("\033[40;35m\t1.�ӷ�����\n\033[0m");
	printf("\033[40;35m\t2.��������\n\033[0m");
	printf("\033[40;35m\t3.�˷�����\n\033[0m");
	printf("\033[40;35m\t4.��������\n\033[0m");
	printf("\033[40;35m\t5.��������\n\033[0m");
	printf("\033[40;35m\t6.ƽ������\n\033[0m");
	printf("\033[40;35m\t7.��������\n\033[0m");
	printf("\033[40;35m\t���������˳�\n\033[0m");
	printf("\033[40;35m\t���������ѡ��:\033[0m");
	int a = 0;
	scanf("%d", &a);
	return (a);
}
int main()
{
	double a, b;
	do
	{
		int ch = pt();
		switch (ch)
		{
		case 1:
			printf("\033[40;34m���������������ӷ�����:\n\033[0m");
			scanf_s("%lf%lf", &a, &b);
			printf("\033[40;33m%lf + %lf=%lf\n\033[0m", a, b, a + b);
			break;
		case 2:
			printf("\033[40;34m����������������������:\n\033[0m");
			scanf_s("%lf%lf", &a, &b);
			printf("\033[40;33m%lf �C %lf=%lf\n\033[0m", a, b, a - b);
			break;
		case 3:
			printf("\033[40;34m���������������˷�����:\n\033[0m");
			scanf("%lf%lf", &a, &b);
			printf("\033[40;33m%lf �� %lf=%lf\n\033[0m", a, b, a * b);
			break;
		case 4:
			printf("\033[40;34m����������������������:\n\033[0m");
			scanf("%lf%lf", &a, &b);
			printf("\033[40;33m%lf �� %lf=%lf\n\033[0m", a, b, a / b);
			break;
		case 5:
			printf("\033[40;34m����������������������:\n\033[0m");
			scanf("%lf%lf", &a, &b);
			printf("\033[40;33m%lf �� %lf=%lf\n\033[0m", a, b, fmod(a, b));
			break;
		case 6:
			printf("\033[40;34m��������������ƽ������:\n\033[0m");
			scanf("%lf%lf", &a, &b);
			printf("\033[40;33m%lf��%lfƽ��Ϊ%lf\n\033[0m", a, b, pow(a, b));
			break;
		case 7:
			printf("\033[40;34m����������������������:\n\033[0m");
			scanf("%lf%lf", &a, &b);
			printf("\033[40;34m%lf��%lf����Ϊ%lf\n\033[0m", a, b, pow(a, 1 / b));
			break;
		default:
			printf("\033[40;31m�˳���...\n\033[0m");
			goto et;
			break;
		}
	} while (1);
et:
	return 0;
}