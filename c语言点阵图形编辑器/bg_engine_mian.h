/*
C���Ե���ͼ�ο�
graph_engine_mian.h ͼ������ͷ�ļ�
creat_graph_file.h ����ͼ���ļ�(creat_graph)
load_graph_file.h ����ͼ���ļ�(load_graph)
print_graph_file.h ��ʾͼ��(print_graph)
editor_graph.h �༭ͼ��(editor_graph)
sava_graph_file.h ����ͼ�ε��ļ�(editor_graph)

int creat_graph(int x,int y,char* filename) ����һ��ͼ���ļ�
int cheak_graph_file(char* filename) ���ͼ���ļ��Ƿ�Ϊ��,�շ���0,���򷵻�1
int** load_graph(int x, int y, char* filename) ����ͼ���ļ�����һ����ά����
int print_graph(int x, int y,int model, int** array,char *filename) 
��ʾͼ���ļ�,ģʽ1Ϊ��ʾͼ���ļ�,2Ϊ����ά����ת��ͼ�β���ʾ���м�ͼ��,3Ϊ����ά����ת��ͼ��ֱ����ʾ
int editor_graph(int x, int y, int** array,int c)�޸Ķ�ά����,cֻ֧��0��1
int graph_merge(char* merge_filename1, char* merge_filename2, char* merge_filename,int n)
merge_filename1��merge_filename2ΪҪ�ϳɵ�ͼ��·��,merge_filename�ϳɺ��ͼ��·��,n�ϲ����
int sava_graph(int x, int y, int model, int** array, char* filename) 
ģʽ1Ϊ����ά����ת���ɶ�άͼ�����鲢����,ģʽ2Ϊ����ά����ת����ͼ�����ݲ�����
int free_graph(int x, int** array) �ͷŶ�ά����

���ض�˵��,x��y�ֱ��������������,filename�����ļ�·��,array�����ά����,model������Ҫ��ִ��ģʽ
�½�ͼ���ļ�����Ϊȫ��Ϊ1;���غ���ʾ�½�ͼ���ļ�����ά���鲻�޸����ݶ�ά�����Ϊ1
�����ļ����½��ļ�����1��0,0��1��0��". ",1��"  "����
����ִ�����󷵻�1,���󷵻�0,��������麯���Ƿ�˳��ִ��
*/
#ifndef BG_ENGINE_MIAN_H
#define BG_ENGINE_MIAN_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "creat_graph_file.h"
#include "load_graph_file.h"
#include "print_graph.h"
#include "editor_graph.h"
#include "sava_graph_file.h"
#endif // !GRAPH_ENGINE_MIAN_H

