#include <iostream>
using namespace std;
#include <algorithm>
#include <list>


// 这个居然超时了我的天,不是让我们用链表模拟吗
// int main(int argc, char const *argv[]) {
//     unsigned n;
//     cin >> n;
//     list<int> game(n);
//     // iota(game.begin(), game.end(), 1);
//     unsigned i = 0;
//     generate(game.begin(), game.end(), [&i]() { return ++i; });
//     list<int>::iterator it = game.begin();
//     while (game.size() > 1) {
//         for (size_t i = 0; i < 2; i++) {
//             it++;
//             if (it == game.end()) {
//                 it = game.begin();
//             }
//         }
//         it = game.erase(it);
//         if (it == game.end()) {
//             it = game.begin();
//         }
//     }
//     cout << game.front();
//     return 0;
// }

typedef long long ll;
ll J(ll n, ll m) {
    ll res = 0;
    for (size_t i = 1; i <= n; i++) {
        res = (res + m) % i;
    }
    return res + 1;
}

// 直接上公式大法
int main(int argc, char const *argv[]) {
    unsigned n;
    cin >> n;
    cout << J(n, 3) << endl;
}
/*
Description
有n个人围成一圈，从第1个人开始报数1、2、3，每报到3的人退出圈子。编程使用链表找出最后留下的人。



输入格式
输入一个数n，1000000>=n>0


输出格式
输出最后留下的人的编号


输入样例
3


输出样例
2
 */
