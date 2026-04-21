#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    unsigned n, m;
    while (cin >> n >> m && n != 0 && m != 0) {
        // 想着是排序然后二分查找
        vector<unsigned> dragon(n);
        vector<unsigned> hero(m);
        // 扫入
        for (size_t i = 0; i < n; i++) {
            cin >> dragon[i];
        }
        for (size_t i = 0; i < m; i++) {
            cin >> hero[i];
        }
        // sort
        sort(dragon.begin(), dragon.end());
        sort(hero.begin(), hero.end());
        unsigned cost = 0;
        bool flag = true;
        auto curr = hero.begin();
        for (size_t i = 0; i < n; i++) {
            auto it = lower_bound(curr, hero.end(), dragon[i]); // stl里面有算法是直接实现的直接拿来用算了。
            if (it == hero.end()) {
                flag = false;
                break;
            } else {
                cost += *it;
                curr = it + 1;
            }
        }
        if (flag) {
            cout << cost << '\n';
        } else {
            cout << "Loowater is doomed!" << '\n';
        }
    }
    return 0;
}


/*
Description
有n个头的恶龙，你希望雇一些骑士把它杀死（即砍掉所有头）。村里有ｍ个骑士可以雇佣，一个能力值为x的骑士可以砍掉恶龙
一个直径不超过x的头，且需要支付x个金币。如何雇佣骑士才能砍掉恶龙的所有头，且需要支付的金币最少？注意，一个骑士只
能砍一个头（且不能被雇佣两次）



输入格式
多组数据，每组数据的第一行为正整数n和m(1<=n,m<=200000)；以下n行每行为一个整数，即恶龙每个头的直径；以下m行每行为
一个整数，即每个骑士的能力。输入结束标志ｎ＝ｍ＝0;


输出格式
输出格式：每组数据，输出最少花费，无解输出"Loowater is doomed!"


输入样例
2 3
5
4
7
8
4

2 1
5
5
10

0 0


输出样例
11
Loowater is doomed!
*/
