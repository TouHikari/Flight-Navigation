/*
* File: dijkstra.c
* Date: 2024-12-23
* Description: 实现最短路径算法（Dijkstra算法）。
*/

#include <stdio.h>
#include <limits.h>
#include "../include/dijkstra.h"
#include "../include/input_output.h"

// 找到当前未处理的顶点中，距离源顶点最近的一个顶点
int minDistance(int dist[], int sptSet[], int vertices)
{
    int min = INT_MAX, minIndex;
    for (int v = 0; v < vertices; v++)
    {
        if (sptSet[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex; // 返回最近的顶点索引
}

// Dijkstra 算法实现
void dijkstra(Graph *graph, int src)
{
    int dist[graph->vertices]; // 存储每个顶点的最短距离
    int sptSet[graph->vertices]; // 标记已处理的顶点

    // 初始化
    for (int i = 0; i < graph->vertices; i++)
    {
        dist[i] = INT_MAX; // 初始化为无穷大
        sptSet[i] = 0; // 未处理
    }
    dist[src] = 0; // 源点距离为0

    // 处理所有顶点
    for (int count = 0; count < graph->vertices - 1; count++)
    {
        // 找到最小距离的顶点
        int u = minDistance(dist, sptSet, graph->vertices);
        sptSet[u] = 1; // 标记为已处理

        // 更新邻接顶点的距离
        for (int v = 0; v < graph->vertices; v++)
        {
            if (!sptSet[v] && dist[u] != INT_MAX &&
                graph->adjMatrix[u][v] != INT_MAX && 
                dist[u] + graph->adjMatrix[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph->adjMatrix[u][v]; // 更新最短路径
            }
        }
    }

    printShortestPath(dist, graph->vertices); // 打印最短路径
}
