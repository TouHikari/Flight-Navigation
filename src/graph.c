/*
* File: graph.c
* Date: 2024-12-23
* Description: 定义图的数据结构，使用邻接矩阵表示航班之间的连接，打印 ASCII 图示。
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/graph.h"

// 初始化图的邻接矩阵
void initGraph(Graph *graph, int vertices)
{
    graph->vertices = vertices;

    // 为邻接矩阵分配内存
    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));

        // 初始化邻接矩阵，0表示自环，其他为无穷大
        for (int j = 0; j < vertices; j++)
        {
            graph->adjMatrix[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
}

// 添加边到图中
void addEdge(Graph *graph, int src, int dest, int weight)
{
    // 设置源到目标的边权重
    graph->adjMatrix[src][dest] = weight;
    // 无向图，反向边也要设置
    graph->adjMatrix[dest][src] = weight;
}

// 释放图的内存
void freeGraph(Graph *graph)
{
    for (int i = 0; i < graph->vertices; i++)
    {
        // 释放每一行
        free(graph->adjMatrix[i]);
    }

    // 释放邻接矩阵的指针
    free(graph->adjMatrix);
}

// 打印图的 ASCII 可视化
void printGraph(Graph *graph)
{
    printf(_YELLOW("图的邻接矩阵表示:\n"));

    // 打印表头
    printf("\t");
    for (int i = 0; i < graph->vertices; i++)
    {
        printf("%d\t", i);
    }
    printf("\n");

    // 打印矩阵内容
    for (int i = 0; i < graph->vertices; i++)
    {
        // 打印行头
        printf("%d\t", i);

        for (int j = 0; j < graph->vertices; j++)
        {
            int weight = graph->adjMatrix[i][j];

            if (weight == INT_MAX)
            {
                // 输出蓝色的∞
                printf(_BLUE("∞\t"));
            }
            else
            {
                // 计算所有边的最大值
                int maxWeight = 0;

                for (int k = 0; k < graph->vertices; k++)
                {
                    if (graph->adjMatrix[i][k] != INT_MAX &&
                        graph->adjMatrix[i][k] > maxWeight)
                    {
                        maxWeight = graph->adjMatrix[i][k];
                    }
                }

                // 确定颜色
                if (weight <= maxWeight * 0.33)
                {
                    // 0 ~ 33%：绿色
                    printf(_GREEN("%d\t"), weight);
                }
                else if (weight <= maxWeight * 0.66)
                {
                    // 33% ~ 66%：黄色
                    printf(_YELLOW("%d\t"), weight);
                }
                else
                {
                    // 66% ~ 100%：红色
                    printf(_RED("%d\t"), weight);
                }
            }
        }
        printf("\n");
    }

    // 打印 ASCII 图
    printf(_YELLOW("ASCII 图示:\n"));
    for (int i = 0; i < graph->vertices; i++)
    {
        // 打印节点编号
        printf("节点 " _YELLOW("%d") ": ", i);

        int hasEdge = 0; // 标识当前节点是否有边
        for (int j = 0; j < graph->vertices; j++)
        {
            // 确保非自环
            if (graph->adjMatrix[i][j] != INT_MAX && i != j)
            {
                if (hasEdge)
                {
                    // 边之间用空格分隔
                    printf(" ");
                }

                // 打印边和目标节点
                printf("--[%d]--> " _YELLOW("%d"), graph->adjMatrix[i][j], j);

                hasEdge = 1; // 标记有边
            }
        }
        printf("\n");
    }

    printf("\n");
}
