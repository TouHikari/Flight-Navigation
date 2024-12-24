/*
* File: navigation.c
* Date: 2024-12-23
* Description: 根据用户需求优化路径。
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/navigation.h"
#include "../include/dijkstra.h"

// 优化路径
void optimizePath(Graph *graph, int start, int end)
{
    int dist[graph->vertices];
    int path[graph->vertices];
    int sptSet[graph->vertices];

    for (int i = 0; i < graph->vertices; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        path[i] = -1;
    }
    dist[start] = 0;

    for (int count = 0; count < graph->vertices - 1; count++)
    {
        int u = minDistance(dist, sptSet, graph->vertices);
        sptSet[u] = 1;

        for (int v = 0; v < graph->vertices; v++)
        {
            if (!sptSet[v] && dist[u] != INT_MAX &&
                graph->adjMatrix[u][v] != INT_MAX &&
                dist[u] + graph->adjMatrix[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph->adjMatrix[u][v];
                path[v] = u;
            }
        }
    }

    // 打印优化后的路径
    printOptimizedPath(graph, path, end);
    printPathStats(dist, path, end);
}

// 路径重规划
void replanPath(Graph *graph, int src, int dest, int newWeight)
{
    graph->adjMatrix[src][dest] = newWeight;
    graph->adjMatrix[dest][src] = newWeight; // 无向图

    printf(_YELLOW("边") " (%d, %d) " _YELLOW("的权重已更新为 ") "%d。\n",
           src, dest, newWeight);
}

// 打印优化后的路径
void printOptimizedPath(Graph *graph, int path[], int end)
{
    if (path[end] == -1)
    {
        printf(_RED("没有找到路径。\n"));
        return;
    }

    printf(_YELLOW("优化后的路径: "));
    int current = end;
    int stack[graph->vertices];
    int top = -1;

    while (current != -1)
    {
        stack[++top] = current;
        current = path[current];
    }

    while (top >= 0)
    {
        printf("%d ", stack[top--]);
        if (top >= 0)
        {
            printf("-> ");
        }
    }
    printf("\n");
}

// 输出路径统计信息
void printPathStats(int dist[], int path[], int end)
{
    if (dist[end] == INT_MAX)
    {
        printf(_RED("到达") " %d " _RED("的路径不可达。\n"), end);
    }
    else
    {
        printf(_YELLOW("到达") " %d " _YELLOW("的最短距离为: ") "%d\n",
               end, dist[end]);

        // 计算经过的节点数量
        int count = 0;
        int current = end;
        while (current != -1)
        {
            count++;
            current = path[current];
        }
        // 减去起点
        count -= 1; 
        printf(_YELLOW("经过的节点数量: ") "%d\n", count);
    }
}
