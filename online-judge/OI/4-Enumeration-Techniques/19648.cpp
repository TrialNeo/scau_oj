#include <iostream>
using namespace std;

typedef long long ll;
int main() {
    ll k = 0;
    scanf("%ld", &k);
    ll x = k + 2;
    for (ll y = k + 1; x >= y; y++) {
        ll q = k * y / (y - k);
        if (q * (y - k) == k * y) {
            x = q;
            printf("1/%ld=1/%ld+1/%ld\n", k, x, y);
        }
    }
}

/*
19648 分数拆分
时间限制:1000MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC

描述：
输入一个正整数，找到所有的正整数x>=y,使得1/k=1/x+1/y

输入格式：
一个正整数n，n<=100000

输出格式：
一行一个分式等式
小的分数显示在前面；多个等式，等式右边第一个分数小的先输出

输入样例：
2

输出样例：
1/2=1/6+1/3
1/2=1/4+1/4
*/
