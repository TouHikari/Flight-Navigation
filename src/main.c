/*
* File: main.c
* Date: 2024-12-23
* Description: 程序的入口点，启动用户交互。
*/

#include <stdio.h>
#include <windows.h>
#include "../include/user_interface.h"
#include "../include/colors.h"

// 主函数
int main(void)
{
    // 若为 Windows 系统则将命令行编码更改为 UTF-8
    #ifdef _WIN32
    system("CHCP 65001");
    #endif

    // 启动用户交互
    userInteraction();

    printf(_GREEN("程序退出。按回车键关闭窗口..."));
    getchar();
    
    return 0; // 正常结束
}
