/*
C语言点阵图形库
graph_engine_mian.h 图形引擎头文件
creat_graph_file.h 创建图形文件(creat_graph)
load_graph_file.h 加载图形文件(load_graph)
print_graph_file.h 显示图形(print_graph)
editor_graph.h 编辑图形(editor_graph)
sava_graph_file.h 保存图形到文件(editor_graph)

int creat_graph(int x,int y,char* filename) 创建一个图形文件
int cheak_graph_file(char* filename) 检查图形文件是否为空,空返回0,否则返回1
int** load_graph(int x, int y, char* filename) 加载图形文件返回一个二维数组
int print_graph(int x, int y,int model, int** array,char *filename) 
显示图形文件,模式1为显示图形文件,2为将二维数组转换图形并显示行列加图形,3为将二维数组转换图形直接显示
int editor_graph(int x, int y, int** array,int c)修改二维数组,c只支持0和1
int graph_merge(char* merge_filename1, char* merge_filename2, char* merge_filename,int n)
merge_filename1和merge_filename2为要合成的图形路径,merge_filename合成后的图形路径,n合并间隔
int sava_graph(int x, int y, int model, int** array, char* filename) 
模式1为将二维数组转换成二维图形数组并保存,模式2为将二维数组转换成图形数据并保存
int free_graph(int x, int** array) 释放二维数组

无特定说明,x和y分别代表行数和列数,filename代表文件路径,array代表二维数组,model代表你要的执行模式
新建图形文件数据为全部为1;加载和显示新建图形文件到二维数组不修改数据二维数组均为1
保存文件则将新建文件数据1变0,0变1或0变". ",1变"  "保存
程序执行无误返回1,错误返回0,可用来检查函数是否顺利执行
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

