#ifndef LOAD_GRAPH_FILE_H
#define LOAD_GRAPH_FILE_H
int cheak_graph_file(char* filename)
{
	FILE* fp;
	if ((fp = fopen(filename, "r+")) == NULL)
	{
		return 0;
	}
	int c = fgetc(fp);
	if (c == -1)
	{
		fclose(fp);
		return 0;
	}
	else;
	fclose(fp);
	return 1;
}
int** load_graph(int x, int y, char* filename)
{
	FILE* fp;
	if ((fp = fopen(filename, "r+")) == NULL)
	{
		return 0;
	}
	int** array = (int**)malloc(sizeof(int*) * x);
	int b, c, d;
	for (b = 0; b < x; ++b)
	{

		array[b]= (int*)malloc(sizeof(int) * y);
		for (c = 0; c < y; ++c)
		{
			fscanf(fp, "%1d", &d);
			array[b][c] = d;
		}
	}
	fclose(fp);
	return array;
}
#endif // !LOAD_GRAPH_FILE_H
