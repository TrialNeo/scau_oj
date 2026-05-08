#include <iostream>
using namespace std;

typedef long long ll;

bool check(int k, int m) {
    int pos = 0;
    for (int i = 0; i < k; i++) {
        pos = (pos + m - 1) % (2 * k - i);

        if (pos < k) {
            return false;
        }
    }
    // 如果顺利杀够了 k 个人都没碰到好人，返回 true
    return true;
}


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k = 0;
    while (cin >> k && k != 0) {
        for (size_t i = k + 1;; i++) {
            if (check(k, i)) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}


/* 描述
约瑟夫问题是个有名的问题：N个人围成一圈，从第一个开始报数，报数为第M个的将出列，下一个人接着重新开始报数，重复这个过程，最后剩下一人。例如N=6，M=5，出列的顺序是：5、4、6、2、3，最后1剩下。

现在有这么一个游戏来模拟约瑟夫问题，所有人围成一圈，且将人员分成两组，每组有k个人，前k个是第一组的人员，后k个是第二组的人员，假设你现在是第一组的组长，你必须确定最小m，使到所有第二组的人员都在第一组的人员前出列，
这样你们组就可以获胜。
输入格式
输入包含多行，每行输入一个k（0 < k < 14），表示每组的人员数目；
当输入k为0时表示输入结束。

输出格式
对于每个输入的非0的k输出单独一行，包含与输入k相对应的m。

输入样例
3
4
0
输出样例
5
30

*/
