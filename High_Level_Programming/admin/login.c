// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/20.

#include "login.h"

enum LOGIN_STATUS {
    SUCCESS,
    PASSWORD_INCORRECT,
    ERROR
};
typedef enum LOGIN_STATUS LOGIN_STATUS;

//用户登录
LOGIN_STATUS login(char *password) {
    //传入的是明文，我们要对此进行简单的加密，可惜不能用ECDH+Des，RSA之类的，不然还能更安全


    return ERROR;
}