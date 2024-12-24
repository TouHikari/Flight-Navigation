/*
* File: user_interface.c
* Date: 2024-12-23
* Description: 提供简单的用户界面，允许用户输入起点、终点和选择的优化策略。
*/

#include <stdio.h>
#include "../include/user_interface.h"
#include "../include/input_output.h"
#include "../include/dijkstra.h"
#include "../include/navigation.h"

// 显示主菜单
void displayMenu()
{
    printf(_YELLOW("主菜单:\n"));
    printf(_YELLOW("1. 输入图信息\n"));
    printf(_YELLOW("2. 计算最短路径\n"));
    printf(_YELLOW("3. 修改边权重\n"));
    printf(_YELLOW("4. 显示图的当前状态\n"));
    printf(_YELLOW("5. 退出\n"));
}

// 用户交互函数
void userInteraction(void)
{
    Graph graph; // 创建图结构
    char choice;
    int ifHasGraph = 0;

    while (1)
    {
        char input;
        displayMenu();
        printf(_RED("请输入您的选择: "));
        scanf("%c", &choice);
        while ((input = getchar()) != '\n')
        {
            continue;
        }

        switch (choice)
        {
            case '1':
                ifHasGraph = 1;
                readGraph(&graph);
                break;
            case '2':
            {
                int start, end;
                printf(_RED("请输入起点和终点 (用空格分隔): "));
                scanf("%d %d", &start, &end);
                optimizePath(&graph, start, end);
                break;
            }
            case '3':
            {
                char modifyChoice;
                printf(_RED("您是否希望修改边的权重? (y/n): "));
                scanf(" %c", &modifyChoice);
                if (modifyChoice == 'y' || modifyChoice == 'Y')
                {
                    int src, dest, newWeight;
                    printf(_RED("请输入要修改的边的起点、终点和新权重: "));
                    scanf("%d %d %d", &src, &dest, &newWeight);
                    replanPath(&graph, src, dest, newWeight);
                }
                break;
            }
            case '4':
                printGraph(&graph);
                break;
            case '5':
                if (ifHasGraph)
                {
                    freeGraph(&graph);
                }
                return;
            default:
                printf(_RED("无效的选择，请重新输入。\n"));
        }
    }
}
