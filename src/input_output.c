/*
* File: input_output.c
* Date: 2024-12-23
* Description: 处理用户输入和结果输出。
*/

#include <stdio.h>
#include "../include/input_output.h"

// 从用户输入读取图的信息
void readGraph(Graph *graph)
{
    int edges, src, dest, weight;

    printf(_RED("请输入顶点数量: "));
    scanf("%d", &graph->vertices);

    // 初始化图
    initGraph(graph, graph->vertices);
    
    printf(_RED("请输入边的数量: "));
    scanf("%d", &edges);
    
    // 循环读取每条边的信息
    for (int i = 0; i < edges; i++)
    {
        printf(_RED("请输入第%d个边 (源顶点、目标顶点、权重): "), i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        // 添加边
        addEdge(graph, src, dest, weight);
        
        // 输出更新后的图
        // 显示当前图的 ASCII 视图
        printGraph(graph);
    }

}

// 打印每个顶点的最短距离
void printShortestPath(int dist[], int n)
{
    printf(_YELLOW("顶点\t最短距离\n"));
    
    for (int i = 0; i < n; i++)
    {
        // 打印顶点和对应的最短距离
        printf("%d \t%d\n", i, dist[i]); 
    }
}
