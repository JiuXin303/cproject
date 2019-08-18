#ifndef EDITOR_GRAPH_H
#define EDITOR_GRAPH_H
int editor_graph(int x, int y, int** array,int c)
{
	if (c == 0 || c == 1)
	{
		int a, b;
		for (a = 0; a < x; ++a)
		{
			for (b = 0; b < y; ++b)
			{
			}
		}
		array[a - 1][b - 1] = c;
		return 1;
	}
	else;
	return 0;
}
int graph_merge(char* merge_filename1, char* merge_filename2, char* merge_filename,int n)
{
	FILE* fp1;
	if ((fp1 = fopen(merge_filename1, "r+")) == NULL)
	{
		return 0;
	}
	FILE* fp2;
	if ((fp2 = fopen(merge_filename2, "r+")) == NULL)
	{
		return 0;
	}
	FILE* fp;
	if ((fp = fopen(merge_filename, "w+")) == NULL)
	{
		return 0;
	}
	char ch1;
	char ch2=NULL;
	int a = 0;
	ch1 = fgetc(fp1);
	while (ch1 != EOF)
	{
		if ((ch1 == '\n')&&(ch2!=EOF))
		{
			for (int b = 0; b < n; ++b)
			{
				fputc(' ', fp);
			}
			while (fputc(ch2 = fgetc(fp2), fp), ch2 != '\n' && ch2 != EOF);
			ch1=fgetc(fp1);
		}
		if (a==0&&ch2 == EOF)
		{
			fputc('\n', fp);
			++a;
		}
		fputc(ch1, fp);
		ch1=fgetc(fp1);
	}
	int b = 0;
	if (ch2 != EOF)
	{
		if (b == 0)
		{
			for (int c = 0; c < n; ++c)
			{
				fputc(' ', fp);
			}
		}
		while ((ch2 = fgetc(fp2)) != EOF)
		{
			fputc(ch2, fp);
		}
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	return 1;
}
#endif // !EDITOR_GRAPH_H

