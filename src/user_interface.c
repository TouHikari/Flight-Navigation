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
    printf(_YELLOW(" ------------------------------- \n"));
    printf(_YELLOW("|\t主菜单:\t\t\t|\n"));
    printf(_YELLOW("|1. 输入图信息\t\t\t|\n"));
    printf(_YELLOW("|2. 计算最短路径\t\t|\n"));
    printf(_YELLOW("|3. 修改边权重\t\t\t|\n"));
    printf(_YELLOW("|4. 显示图的当前状态\t\t|\n"));
    printf(_YELLOW("|5. 退出\t\t\t|\n"));
    printf(_YELLOW(" ------------------------------- \n"));
}

// 用户交互函数
void userInteraction(void)
{
    // 创建图结构
    Graph graph;
    char choice;
    int ifHasGraph = 0;

    while (1)
    {
        // 显示菜单
        displayMenu();

        // 读取输入
        printf(_RED("请输入您的选择: "));
        scanf("%c", &choice);
        emptyInputBuffer();

        // 根据输入选择进行程序
        switch (choice)
        {
            case '1':
                printf(_GREEN("\n-----------开始输入图信息！-----------\n\n"));
                ifHasGraph = 1;
                readGraph(&graph);
                emptyInputBuffer();
                printf(_GREEN("---图信息输入完成！正在返回主菜单...---\n\n"));
                break;

            case '2':
            {
                printf(_GREEN("\n-------开始计算最短路径！-------\n\n"));
                int start, end;
                printf(_RED("请输入起点和终点 (用空格分隔): "));
                scanf("%d %d", &start, &end);
                emptyInputBuffer();
                optimizePath(&graph, start, end);
                printf(_GREEN("---计算完成！正在返回主菜单...---\n\n"));
                break;
            }

            case '3':
            {
                printf(_GREEN("\n--------开始修改边权重！--------\n\n"));
                char modifyChoice;
                int src, dest, newWeight;
                printf(_RED("请输入要修改的边的起点、终点和新权重: "));
                scanf("%d %d %d", &src, &dest, &newWeight);
                emptyInputBuffer();
                replanPath(&graph, src, dest, newWeight);
                printf(_GREEN("---更新完成！正在返回主菜单...---\n\n"));
                break;
            }

            case '4':
                printf(_GREEN("\n-----开始显示图的当前状态！-----\n\n"));
                printGraph(&graph);
                printf(_GREEN("---输出成功！正在返回主菜单...---\n\n"));
                break;

            case '5':
                if (ifHasGraph)
                {
                    freeGraph(&graph);
                    printf(_GREEN("释放内存成功！\n"));
                }
                return;

            // 处理无效输入
            default:
                printf(_RED("无效的选择，请重新输入。\n"));

        }
    }
}

// 清空输入缓冲区
void emptyInputBuffer(void)
{
    char ch;
    while ((ch = getchar()) != '\n')
    {
        continue;
    }
}
