#ifndef SAVA_GRAPH_FILE_H
#define SAVA_GRAPH_FILE_H
int sava_graph(int x, int y, int model, int** array, char* filename)
{
	FILE* fp;
	if ((fp = fopen(filename, "r+")) == NULL)
	{
		return 0;
	}
	int b, c;
	if (model == 1)
	{
		for (b = 0; b < x; ++b)
		{
			for (c = 0; c < y; ++c)
			{
				if ((array[b][c]) == 0)
				{
					fprintf(fp, "0");
				}
				else if ((array[b][c]) == 1)
				{
					fprintf(fp, "1");

				}
			}
			if (b == x - 1)
			{
				break;
			}
			fprintf(fp, "\n");
		}
		fclose(fp);
		return 1;
	}
	else if (model == 2)
	{
		int b, c;
		for (b = 0; b < x; ++b)
		{
			for (c = 0; c < y; ++c)
			{
				if ((array[b][c]) == 0)
				{
					fprintf(fp, ". ");
				}
				else if ((array[b][c]) == 1)
				{
					fprintf(fp, "  ");
				}
			}
			if (b == x - 1)
			{
				break;
			}
			fprintf(fp, "\n");
		}
		fclose(fp);
		return 1;
	}
	else
	{
		fclose(fp);
		return 0;
	}

}
int free_graph(int x, int** array)
{

	for (int b = 0; b < x; ++b)
	{
		free(array[b]);
	}
	free(array);
	return 1;
}
#endif // !SAVA_GRAPH_FILE_H

