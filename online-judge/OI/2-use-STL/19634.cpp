#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    int n = 0, m = 0;
    scanf("%d", &n);
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int t = 0;
        scanf("%d", &t);
        auto index = lower_bound(arr.begin(), arr.end(), t);
        arr.insert(index, t);
        if (arr.size() % 2) {
            printf("%d\n", arr[arr.size() / 2]);
        } else {
            printf("%g\n", (arr[arr.size() / 2] + arr[arr.size() / 2 - 1]) / 2.0); //这里得用%g，太坑了给的测试案例
        }
    }


    return 0;
}


/*
描述：
给定n个有序整数构成的序列，之后做m次操作，每次操作给定一个整数，要求将该整数安插到有序序列当中，之后序列仍然保持有序，每一次操作之后，输出当前序列的中位数。(中位数是指，当序列为奇数个数时，中位数为排在中间的那个数字，当序列为偶数个数时，中位数为排在中间的两个数之和的一半)

输入格式：
第一行为n
第二行为n个整数，以空格分割
第三行为m
第四行为m个整数，以空格分割

输出格式：
m行，每行一个输出的中位数

输入样例：
3
1 5 9
2
3 10

输出样例：
4
5
*/
