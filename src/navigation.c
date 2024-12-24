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
    // dist 数组存储从起点到每个顶点的最短距离
    int dist[graph->vertices];
    // path 数组存储每个顶点的前驱顶点，用于回溯路径
    int path[graph->vertices];
    // sptSet 数组标记已处理的顶点
    int sptSet[graph->vertices];

    // 初始化 dist、sptSet 和 path 数组
    for (int i = 0; i < graph->vertices; i++)
    {
        // 设置初始值为无穷大
        dist[i] = INT_MAX;
        // 未处理
        sptSet[i] = 0;
        // 前驱顶点初始化为 -1
        path[i] = -1;
    }
    // 起点到自身的距离为 0
    dist[start] = 0;

    // 处理所有顶点
    for (int count = 0; count < graph->vertices - 1; count++)
    {
        // 找到当前未处理的顶点中，距离起点最近的一个顶点
        int u = minDistance(dist, sptSet, graph->vertices);
        // 标记该顶点为已处理
        sptSet[u] = 1;

        // 更新与当前顶点相邻的未处理顶点的距离
        for (int v = 0; v < graph->vertices; v++)
        {
            // 只处理未处理的顶点，并检查路径是否可达
            if (!sptSet[v] && dist[u] != INT_MAX &&
                graph->adjMatrix[u][v] != INT_MAX &&
                dist[u] + graph->adjMatrix[u][v] < dist[v])
            {
                // 更新最短路径
                dist[v] = dist[u] + graph->adjMatrix[u][v];
                // 记录前驱顶点
                path[v] = u;
            }
        }
    }

    // 打印优化后的路径
    printOptimizedPath(graph, path, end);
    // 打印路径统计信息，包括最短距离和经过的节点数量
    printPathStats(dist, path, end);
}

// 路径重规划
void replanPath(Graph *graph, int src, int dest, int newWeight)
{
    // 更新邻接矩阵中的边权重
    // 更新源到目标的边权重
    graph->adjMatrix[src][dest] = newWeight;
    // 更新目标到源的边权重（无向图）
    graph->adjMatrix[dest][src] = newWeight;

    // 输出更新信息
    printf(_YELLOW("边") " (%d, %d) " _YELLOW("的权重已更新为 ") "%d。\n",
           src, dest, newWeight);
    printf("\n");
}

// 打印优化后的路径
void printOptimizedPath(Graph *graph, int path[], int end)
{
    // 如果没有找到路径，则输出提示信息
    if (path[end] == -1)
    {
        printf(_RED("没有找到路径。\n"));
        return;
    }

    // 输出优化后的路径
    printf(_YELLOW("优化后的路径: "));
    // 从终点开始回溯
    int current = end;
    // 使用栈来存储路径
    int stack[graph->vertices];
    // 栈顶指针
    int top = -1;

    // 回溯路径，直到达到起点
    while (current != -1)
    {
        // 将当前节点压入栈中
        stack[++top] = current;
        // 移动到前驱节点
        current = path[current];
    }

    // 反向输出路径
    while (top >= 0)
    {
        // 输出栈顶元素
        printf("%d ", stack[top--]);

        if (top >= 0)
        {
            // 添加箭头分隔符
            printf("-> ");
        }
    }
    printf("\n");
}

// 输出路径统计信息
void printPathStats(int dist[], int path[], int end)
{
    // 检查目标节点是否可达
    if (dist[end] == INT_MAX)
    {
        printf(_RED("到达") " %d " _RED("的路径不可达。\n"), end);
    }
    else
    {
        // 输出最短距离
        printf(_YELLOW("到达") " %d " _YELLOW("的最短距离为: ") "%d\n",
               end, dist[end]);

        // 计算经过的节点数量
        int count = 0;
        int current = end;

        while (current != -1)
        {
            // 每经过一个节点计数
            count++;
            // 移动到前驱节点
            current = path[current];
        }
        
        // 减去起点
        count -= 1; 
        printf(_YELLOW("经过的节点数量: ") "%d\n", count);
    }
    printf("\n");
}