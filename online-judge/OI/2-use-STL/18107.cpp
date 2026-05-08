#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


// 定义一下选手
struct Player {
    unsigned num; // 通过题目数量
    unsigned cost; // 用时
    char name[20];
};


// 多排序，做一下两个权重就行有现成的sort
void bullet_sort_player(vector<Player> arr) {
    // 居然没有限制空间复杂度，那我们有多少用多少
        
}


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    unsigned n = 0;
    scanf("%u", &n);
    vector<Player> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%u %u %s", &arr[i].num, &arr[i].cost, arr[i].name);
    }


    for (const auto &p: arr) {
        puts(p.name);
    }
    return 0;
}
