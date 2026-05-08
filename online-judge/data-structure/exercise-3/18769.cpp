#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

// 思路就是双指针，前面的指针p，和后面的指针q，先在前面从前往后一直找，直到遇到 arr[p] > 0的情况停止遍历
// 后面也是同样的道理从后往前找 直到遇到arr[q] < 0
// 的情况停下来。然后现在就是需要进行交换了，交换未完成之后再次从头找起就对了
void sep_pos_neg(vector<ll> &arr) {
    if (arr.empty()) {
        return;
    }

    unsigned p = 0, q = arr.size() - 1;
    while (p < q) {
        while (arr[p] < 0 && p < q) {
            p++;
        }
        while (arr[q] > 0 && p < q) {
            q--;
        }
        if (p < q) {
            swap(arr[p], arr[q]);
            p++;
            q--;
        }
    }
}


int main(int argc, char const *argv[]) {
    // 两个桶就能搞定了,居然不给用桶排序也是很离谱
    // 还得是双指针
    unsigned n = 0, m = 0;
    scanf("%u", &m);
    for (size_t i = 0; i < m; i++) {
        scanf("%u", &n);
        vector<ll> arr(n);
        for (int j = 0; j < n; j++) {
            scanf("%lld", &arr[j]);
        }
        sep_pos_neg(arr);
        for (int j = 0; j < n; j++) {
            printf("%lld ", arr[j]);
        }
        puts("");
    }
    return 0;
}


/*
Description
一个数组只包含正负整数，请使用一个O（n）级别的算法对其进行排序。
只需将负数全部放前面，正数全部放后面即可，无需进行严格排序。
此题目必须使用双指针法才能通过，
双指针，指的是在遍历对象的过程中，不是普通的使用单个指针进行访问，
而是使用两个相反方向（对撞指针）的指针进行扫描，从而达到相应的目的。
具体算法如下：
定义两个指针：i=1，j=n
（1）i指针从左至右遍历，当碰到不满足条件的元素（正数），我们暂停i 移动
（2）j指针从右至左遍历，当碰到不满足条件的元素（负数），我们暂停 j 移动
（3）交换两个指针i和j指向的元素
（4）重复 1，2，3 步骤，直到i和j相遇


题目包含T组数据。

输入格式
第一行一个整数T,表示数据的组数。（1<=T<=10）
下面共2*T行，每两行为一组数据。
第i组数组的第一行为整数n，（1<=n<=100000）表示数组的大小，第二行为n个整数。


输出格式
共T行，排序后的T组数据。


输入样例
    2
    3
    1 -1 2
    4
    -1 2 3 -4


输出样例
-1 1 2
-1 -4 3 2

*/
