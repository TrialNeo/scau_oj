// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/20 22:26.

#include "store.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../utils/crypto.h"
#include "string.h"
const char file_crypto_key[16] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};


// 模仿csv格式,作为分隔符
void data_load() {
    FILE *file = fopen("./data", "rb");
    // 加密的，先解密一下
    fseek(file, 0, SEEK_END);
    unsigned size = ftell(file), len = 0;
    rewind(file);
    char *paint_text_buffer = malloc(size), *buffer = 0;

    fread(paint_text_buffer, size, 1, file);
    if (decrypt(file_crypto_key, paint_text_buffer, size, &buffer, &len)) {
    }
}


void data_rewrite() {}


// int main(int argc, char *argv[]) {
//     time_t current_time = time(NULL); // 获取当前时间戳
//
//     return 0;
// }
