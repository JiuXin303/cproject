#include "bg_engine_mian.h"
int printf_bg_mian(void)
{
	printf("1.显示图形文件\n");
	printf("2.显示图形\n");
	printf("输入其它数字退出\n");
	printf("请输入你的选项:");
	int a;
	scanf("%d", &a);
	return a;
}
int editor_bg_mian(int x, int y, int** array, char* filename)
{
	while (1)
	{
		print_graph(x, y, 2, array, filename);
		printf("\n图形编辑\n");
		printf("编辑的图形文件路径:%s\n", filename);
		printf("1.显示图形\n");
		printf("2.修改图形\n");
		printf("3.保存图形\n");
		printf("输入其它数字退出\n");
		printf("请输入你的选项:");
		int a;
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("显示图形\n");
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
			printf("修改图形\n");
			int c, d, e;
			printf("请输入修改图形文件行:");
			scanf(" %d", &c);
			if (c > x||c<=0)
			{
				printf("输入错误\n");
				break;
			}
			printf("请输入修改图形文件列:");
			scanf(" %d", &d);
			if (d > y || d <= 0)
			{
				printf("输入错误\n");
				break;
			}
			printf("请输入修改的数据（只支持0或1,0是'. ',1是'  '）:");
			scanf(" %d", &e);
			if (e == 0 || e == 1)
			{
				editor_graph(c, d, array, e);
			}
			else
			{
				printf("输入错误\n");
			}
			break;
		case 3:
			printf("保存图形\n");
			printf("1.保存数据\n");
			printf("2.保存图形\n");
			printf("请输入你的选项:");
			int g;
			scanf("%d", &g);
			if (g == 1 || g == 2)
			{
				sava_graph(x, y, g, array, filename);
			}
			else
			{
				printf("输入错误\n");
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
		printf("C语言点阵图形编辑器\n");
		printf("1.图形编辑\n");
		printf("2.合并图形\n");
		printf("输入其它数字退出\n");
		printf("请输入你的选项:");
		int a;
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("是否创建新图形文件(y.创建 n.退出):");
			int x, y;
			char a;
			char filename[255];
			scanf(" %c", &a);
			switch (a)
			{
			case 'y':
				printf("请输入创建图形文件路径:");
				scanf("%s", filename);
				strcat(filename, ".bg");
				printf("请输入创建图形文件总行:");
				scanf("%d", &x);
				printf("请输入创建图形文件总列:");
				scanf("%d", &y);
				creat_graph(x, y, filename);
				int** array = load_graph(x, y, filename);
				editor_bg_mian(x, y, array, filename);
				break;
			case 'n':
				printf("退出中...\n");
				return 0;
				break;
			}
			break;
		case 2:
			printf("合并图形\n");
			printf("请输入待合并的图形路径:");
			char merge_filename1[255];
			scanf("%s", merge_filename1);
			strcat(merge_filename1, ".bg");
			printf("请输入要合并的图形路径:");
			char merge_filename2[255];
			scanf("%s", merge_filename2);
			strcat(merge_filename2, ".bg");
			printf("请输入合并后的图形路径:");
			char merge_filename[255];
			scanf("%s", merge_filename);
			strcat(merge_filename, ".bg");
			printf("请输入合并间隔:");
			int n;
			scanf("%d", &n);
			graph_merge(merge_filename1, merge_filename2, merge_filename, n);
			break;
		default:printf("退出中...\n"); return 0; break;
		}
	}
}
