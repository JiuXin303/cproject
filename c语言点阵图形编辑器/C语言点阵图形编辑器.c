#include "bg_engine_mian.h"
int printf_bg_mian(void)
{
	printf("1.��ʾͼ���ļ�\n");
	printf("2.��ʾͼ��\n");
	printf("�������������˳�\n");
	printf("���������ѡ��:");
	int a;
	scanf("%d", &a);
	return a;
}
int editor_bg_mian(int x, int y, int** array, char* filename)
{
	while (1)
	{
		print_graph(x, y, 2, array, filename);
		printf("\nͼ�α༭\n");
		printf("�༭��ͼ���ļ�·��:%s\n", filename);
		printf("1.��ʾͼ��\n");
		printf("2.�޸�ͼ��\n");
		printf("3.����ͼ��\n");
		printf("�������������˳�\n");
		printf("���������ѡ��:");
		int a;
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("��ʾͼ��\n");
			int b = printf_bg_mian();
			switch (b)
			{
			case 1:
				print_graph(x, y, 1, array, filename);
				printf("\n");
				break;
			case 2:
				print_graph(x, y, 3, array, filename);
				break;
			}
			break;
		case 2:
			printf("�޸�ͼ��\n");
			int c, d, e;
			printf("�������޸�ͼ���ļ���:");
			scanf(" %d", &c);
			if (c > x||c<=0)
			{
				printf("�������\n");
				break;
			}
			printf("�������޸�ͼ���ļ���:");
			scanf(" %d", &d);
			if (d > y || d <= 0)
			{
				printf("�������\n");
				break;
			}
			printf("�������޸ĵ����ݣ�ֻ֧��0��1,0��'. ',1��'  '��:");
			scanf(" %d", &e);
			if (e == 0 || e == 1)
			{
				editor_graph(c, d, array, e);
			}
			else
			{
				printf("�������\n");
			}
			break;
		case 3:
			printf("����ͼ��\n");
			printf("1.��������\n");
			printf("2.����ͼ��\n");
			printf("���������ѡ��:");
			int g;
			scanf("%d", &g);
			if (g == 1 || g == 2)
			{
				sava_graph(x, y, g, array, filename);
			}
			else
			{
				printf("�������\n");
			}
			break;
		default:
			free_graph(x, array);
			return 0;
			break;
		}
	}
}
int main(void)
{
	while (1)
	{
		printf("C���Ե���ͼ�α༭��\n");
		printf("1.ͼ�α༭\n");
		printf("2.�ϲ�ͼ��\n");
		printf("�������������˳�\n");
		printf("���������ѡ��:");
		int a;
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("�Ƿ񴴽���ͼ���ļ�(y.���� n.�˳�):");
			int x, y;
			char a;
			char filename[255];
			scanf(" %c", &a);
			switch (a)
			{
			case 'y':
				printf("�����봴��ͼ���ļ�·��:");
				scanf("%s", filename);
				strcat(filename, ".bg");
				printf("�����봴��ͼ���ļ�����:");
				scanf("%d", &x);
				printf("�����봴��ͼ���ļ�����:");
				scanf("%d", &y);
				creat_graph(x, y, filename);
				int** array = load_graph(x, y, filename);
				editor_bg_mian(x, y, array, filename);
				break;
			case 'n':
				printf("�˳���...\n");
				return 0;
				break;
			}
			break;
		case 2:
			printf("�ϲ�ͼ��\n");
			printf("��������ϲ���ͼ��·��:");
			char merge_filename1[255];
			scanf("%s", merge_filename1);
			strcat(merge_filename1, ".bg");
			printf("������Ҫ�ϲ���ͼ��·��:");
			char merge_filename2[255];
			scanf("%s", merge_filename2);
			strcat(merge_filename2, ".bg");
			printf("������ϲ����ͼ��·��:");
			char merge_filename[255];
			scanf("%s", merge_filename);
			strcat(merge_filename, ".bg");
			printf("������ϲ����:");
			int n;
			scanf("%d", &n);
			graph_merge(merge_filename1, merge_filename2, merge_filename, n);
			break;
		default:printf("�˳���...\n"); return 0; break;
		}
	}
}