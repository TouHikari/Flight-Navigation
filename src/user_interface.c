/*
* File: user_interface.c
* Date: 2024-12-23
* Description: 提供简单的用户界面，允许用户输入起点、终点和选择的优化策略。
*/

#include <stdio.h>
#include "../include/user_interface.h"
#include "../include/input_output.h"
#include "../include/dijkstra.h"

// 用户交互函数
void userInteraction(void)
{
    Graph graph; // 创建图结构
    readGraph(&graph); // 读取图信息
    
    int start;
    printf("请输入起点: ");
    scanf("%d", &start); // 输入起点
    
    dijkstra(&graph, start); // 计算最短路径

    // 打印图的 ASCII 可视化
    printGraph(&graph);

    freeGraph(&graph); // 释放图的内存
}
