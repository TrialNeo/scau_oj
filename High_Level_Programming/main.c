// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/20.

#include <pthread_signal.h>
#include <stdio.h>

#include "menu/menu.h"
#include <stdbool.h>

#include "admin/login.h"


void init(){
    if (!password_check_set()) {
        printf("因为您是第一次使用，请先设置密码：");
        char password[255] = {0} ;
        scanf(" %s",password);
        puts(password);
        password_set(password);
    }else {
        printf("请输入密码登录：");
        char password[255] = {0};
        scanf(" %s",password);
        while (password_login(password)!= SUCCESS) {
            printf("密码错误，请重新输入:");
            scanf(" %s",password);
        }
        printf("登录成功\n");
    }
}

int main() {

    init();
    int op = 0;
    while (true) {
        menu_welcome();
        printf("请输入您的功能编号:");
        scanf("%d",&op);

        switch (op) {

            case 0:
                return 0;
            default:
                break;
        }
    }
}
