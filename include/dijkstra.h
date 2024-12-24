#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "../include/graph.h"

// Dijkstra 算法
void dijkstra(Graph *graph, int src);
// 找到当前未处理的顶点中，距离源顶点最近的一个顶点
int minDistance(int dist[], int sptSet[], int vertices);

#endif
