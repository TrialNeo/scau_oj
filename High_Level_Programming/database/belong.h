// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/21 13:29.

#ifndef PBM_BELONG_H
#define PBM_BELONG_H
struct belong {
    char name[255];
    long create_stamp; // 创建时间戳,用于排序
    char desc[255]; // 描述
};

typedef struct belong belong;
struct link {
    belong *data;
    struct link *next;
};
typedef struct link *link;
void belong_init();
void belong_unin();
bool belong_add();
#endif // PBM_BELONG_H
