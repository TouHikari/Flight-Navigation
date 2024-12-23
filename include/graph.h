#ifndef GRAPH_H
#define GRAPH_H

#include <limits.h>
#include "../include/output.h"

typedef struct {
    int vertices;      // 图中顶点的数量
    int **adjMatrix;   // 邻接矩阵
} Graph;

void initGraph(Graph *graph, int vertices);
void addEdge(Graph *graph, int src, int dest, int weight);
void freeGraph(Graph *graph);
void printGraph(Graph *graph);

#endif