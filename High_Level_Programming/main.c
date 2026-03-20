// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/20.

#include <stdio.h>

#include "menu/menu.h"
#include <stdbool.h>
int main() {



    char op = 0;
    while (true) {
        menu_welcome();
        printf("请输入您的功能编号:");
        op  = getchar();

        switch (op) {

            case 0:
                return 0;
            default:
                break;
        }
    }
}