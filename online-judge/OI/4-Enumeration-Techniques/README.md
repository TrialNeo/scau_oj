## 1 18443
这个上课老师说过，不要直接用暴力枚举，不然性能非常低下
$$
	abcde/fghij=n
$$
对于这个来说，$n>1,n\in N^{+}$
这样看来
这是检查的算法应该是没有问题的
```cpp
bool check_repeat_num(ll n, ll n2) {
    // 把字符换成string
    string n_str = to_string(n) + to_string(n2);
    for (int i = 0; i < n_str.size(); i++) {
        if (n_str[i] == '0') {
            continue;
        }
        for (int j = i + 1; j <= n_str.size(); j++) {
            if (n_str[i] == n_str[j]) {
                return true;
            }
        }
    }
    return false;
}
```

> [!fail] 这里用了两个循环然后非常性能低下
> ````cpp
> int main() {
>     ll n = 0;
>     while (scanf("%ld", &n) && n) {
>         for (ll i = n; i <= 99999; i++) {
>             if (check_repeat_num(i)) {
>                 continue;
>             }
>             for (ll j = 2; j < i; j++) {
>                 if (check_repeat_num(j)) {
>                     continue;
>                 }
>                 if (i == j * n) {
>                     printf("%05d/%05d\n", i, j);
>                 }
>             }
>         }
>     }
> }
> ````

^5c54da

比较好的想法是，因为公式为
$$
	\frac{abcde}{fghij}=n
$$
我们对他进行变形
$$
abcde=n\cdot fghij	
$$
这样就可以只遍历$fghij$然后再检查这个乘出来的数$abcde$是不是一个五位数，符不符合我们不重复的要求即可
```cpp
int main() {
    ll n = 0;
    while (scanf("%ld", &n) && n) {
        for (ll i = 1; i < 99999; i++) {
            ll l = n * i;
            if (l > 99999) {
                break;
            }
            if (!check_repeat_num(l, i)) {
                printf("%05d/%05d=%d\n", l, i, n);
            }
        }
        putchar('\n');
    }
}
```

## 2 19648
$$
	\frac{1}{k}=\frac{1}{x}+\frac{1}{y} \quad (x\geq y)
$$
根据之前[[#1 18443]][[#^5c54da]]的思路，我们不应该直接去遍历两个值$x$和$k$，而是只是去遍历其中一个，加上一个输入的，再加限制条件，这里我们选择遍历$y$
$$
	\frac{1}{x}= \frac{1}{k}-\frac{1}{y}=\frac{y-k}{ky}\implies x=\frac{ky}{y-k}
$$
然后算出来看看这个$x$是不是一个正整数就行了
就是要符合
$$
	x=\frac{ky}{y-k}\text{, and }x(y-k) = ky 
$$
==这题long long和输出的%ld非常坑不要被坑到了==
```cpp
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
```
