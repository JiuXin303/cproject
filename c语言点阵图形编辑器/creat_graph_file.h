#ifndef CREAT_GRAPH_FILE_H
#define CREAT_GRAPH_FILE_H
int creat_graph(int x,int y,char* filename)
{
	FILE* fp;
	if ((fp = fopen(filename, "w+")) == NULL)
	{
		return 0;
	}
	int a, b;
	for (a = 0; a < x; ++a)
	{
		for (b=0; b < y; ++b)
		{
			fprintf(fp, "%d",1);
		}
		if (a ==x - 1)
		{
			break;
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	return 1;
}
#endif // !CREAT_GRAPH_FILE_H

