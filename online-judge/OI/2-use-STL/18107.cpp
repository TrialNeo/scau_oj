#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


// 定义一下选手
struct Player {
    unsigned num; // 通过题目数量
    unsigned cost; // 用时
    char name[255];
};


// 多排序，做一下两个权重就行有现成的sort
bool cmp(Player &x, Player &y) {
    if (x.num > y.num) {
        return true;
    } else if (x.num == y.num) {
        return x.cost < y.cost;
    } else {
        return false;
    }
}

int main(int argc, char const *argv[]) {
    unsigned n = 0;
    scanf("%u", &n);
    vector<Player> arr(n);
    for (size_t i = 0; i < n; i++) {
        scanf("%u%u%s", &arr[i].num, &arr[i].cost, arr[i].name);
    }
    sort(arr.begin(), arr.end(), cmp);
    for (size_t i = 0; i < n; i++) {
        printf("%s\n", arr[i].name);
    }

    return 0;
}
