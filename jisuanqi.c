#include <stdio.h>
#include <math.h>
int main()
{
    printf("c���Լ�����˵��:\n");
	printf("1.������������������;\n");
	printf("2.��������֧��С�������;\n");
	printf("3.���б������������κβ���Ӱ�죬���˸Ų�����;\n");
	printf("4.�κ�δ������ͬ��Ա�������е��޸Ĳ������������������ƽ⡢���ࡢ���ο����ȣ����˸Ų�����;\n") ;
	printf("5.ͬ��������1,��ͬ�����������������˳�;\n");
    int what;
    scanf("%d",&what); 
    if (what==1)
    {
	goto xunhuan;
    }
	else;
    {
	printf("�˳���...\n"); 
	} 
	return 0;
	xunhuan:
	printf("c���Լ�����\n");
	printf("\n"); 
    printf("1.���������ļӷ�����\n");
    printf("\n"); 
    printf("2.���������ļ�������\n");
    printf("\n"); 
    printf("3.���������ĳ˷�����\n");
    printf("\n"); 
    printf("4.���������ĳ�������\n");
    printf("\n"); 
    printf("5.������������������\n");
    printf("\n"); 
    printf("6.��������ѡ�����˳�\n");
    printf("\n"); 
    printf("��ѡ�����ѡ��\n");
    float shu;
    scanf("%f",&shu);
    if (shu==1)
    {
    printf("���������������ӷ�����\n");
    double a,b;
    scanf("%lf%lf",&a,&b);
    double c=a+b;
    printf("%lf + %lf=%lf\n",a,b,c);
    goto xunhuan;
    }
    else if(shu==2)
    {
    printf("����������������������\n");
    double d,e;
    scanf("%lf%lf",&d,&e);
    double f=d-e;
    printf("%lf �C %lf=%lf\n",d,e,f);
    goto xunhuan;
    }
    else if(shu==3)
   {
    printf("���������������˷�����\n");
    double h,i;
    scanf("%lf%lf",&h,&i);
    double j=h*i;
    printf("%lf �� %lf=%lf\n",h,i,j);
    goto xunhuan;
    }
    else if(shu==4)
    {
    printf("����������������������\n");
    double k,l;
    scanf("%lf%lf",&k,&l);
    double n=k/l;
    printf("%lf �� %lf=%lf\n",k,l,n);
    goto xunhuan;
    }
    else if(shu==5)
    {
    printf("����������������������\n");
    double m,o;
    scanf("%lf%lf",&m,&o); 
    printf("%lf �� %lf=%lf\n",m,o,fmod(m,o));
    goto xunhuan;
    }
    else;
    {
    printf("�˳���...\n");
    }
    return 0; 
 }

