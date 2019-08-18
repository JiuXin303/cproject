#ifndef PRINT_GRAPH_H
#define PRINT_GRAPH_H
int print_graph(int x, int y,int model, int** array,char *filename)
{
	if (model == 1)
	{
		FILE* fp;
		if ((fp = fopen(filename, "r")) == NULL)
		{
			return 0;
		}
		while (!feof(fp))
		{
			int a = fgetc(fp);
			printf("%c", a);
		}
		fclose(fp);
		return 1;
	}
	else if (model==2)
	{
		int b, c;
		for (b = 0; b < x; ++b)
		{
			printf("%d ", b + 1);
			for (c = 0; c < y; ++c)
			{
				printf("%d", c + 1);
				if ((array[b][c]) == 0)
				{
					printf(". ");
				}
				else if ((array[b][c]) == 1)
				{
					printf("  ");
				}
			}
			printf("\n");
		}
	}
	else if (model == 3)
	{
		int b, c;
		for (b = 0; b < x; ++b)
		{
			for (c = 0; c < y; ++c)
			{
				if ((array[b][c]) == 0)
				{
					printf(". ");
				}
				else if ((array[b][c]) == 1)
				{
					printf("  ");
				}
			}
			printf("\n");
		}
	}

	return 1;
}
#endif // !PRINT_GRAPH_H

