#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "../include/graph.h"

// 优化路径
void optimizePath(Graph *graph, int start, int end);

// 路径重规划
void replanPath(Graph *graph, int src, int dest, int newWeight);

// 打印优化后的路径
void printOptimizedPath(Graph *graph, int path[], int end);

// 输出路径统计信息
void printPathStats(int dist[], int path[], int end);

#endif
