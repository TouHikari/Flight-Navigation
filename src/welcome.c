/*
* File: welcome.c
* Date: 2024-12-23
* Description: 显示欢迎界面，介绍 Dijkstra 算法及程序使用方法。
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "../include/colors.h"

// 显示欢迎信息
void displayWelcomeMessage(void)
{
    system("cls"); // 清屏

    printf(_GREEN("欢迎使用最短航班飞行路径计算程序！\n\n"));

    // 程序简介
    printf(_YELLOW("程序简介:\n"));
    printf("该程序可以在复杂的航班网络中找到连接两地的最短路径，\n");
    printf("程序基于 Dijkstra 算法(迪杰斯特拉算法)，能够处理图结构\n");
    printf("的输入，并通过优化路径选择，快速找到从起点到终点的最短\n");
    printf("航班路线！\n");
    printf("该程序适用于需要在航班网络中进行路径规划的工作人员，\n");
    printf("比如航空公司调度员。无论是寻找最短的航班路线，还是\n");
    printf("需要对航班费用进行优化，本程序都能提供很大帮助！\n\n");

    // Dijkstra 算法简介
    printf(_YELLOW("Dijkstra 算法简介:\n"));
    printf("Dijkstra 算法是一种用于计算图中单源最短路径的算法，\n");
    printf("它通过贪心策略在每一步选择当前未处理的顶点中距离源\n");
    printf("顶点最近的一个，并更新与该顶点相邻的顶点的最短路径。\n");
    printf("该算法适用于权重非负的图。\n\n");

    printf(_GREEN("按回车键继续...\n"));
    getchar(); // 等待用户输入

    // 程序使用方法
    printf(_YELLOW("程序使用方法:\n"));
    printf("1. 输入顶点数量和边的数量。\n");
    printf("2. 按照提示输入每条边的信息，包括源顶点、目标顶点和\n");
    printf("   权重。\n");
    printf("3. 选择计算最短路径的起点和终点。\n");
    printf("4. 可以修改边的权重并查看更新后的图。\n");
    printf("5. 退出程序时，确保释放内存资源。\n\n");

    // 相关概念
    printf(_YELLOW("相关概念:\n"));
    printf("1. 图：由顶点和边组成的结构，用于表示实体之间的连接。\n");
    printf("2. 邻接矩阵：表示图的二维数组，用于存储顶点之间的连\n");
    printf("   接权重。\n");
    printf("3. 权重：表示边的成本或距离，通常为非负数。\n");
    printf("4. 自环：从一个顶点到自身的边。\n\n");

    printf(_GREEN("按回车键继续...\n"));
    getchar(); // 等待用户输入
}
