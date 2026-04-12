#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define WHITE 1
#define BLACK 2

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    int n = 0;
    if (!(cin >> n)) {
        return 0;
    }
    vector<int> a(n);
    int white_cow = 0;
    // 录入牛群进来
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == WHITE) {
            white_cow++;
        }
    }
    /*
    想法是把左边的 黑色奶牛全部变白  右边的白色奶牛全部变黑
    然后记录左边白奶牛的数量，因为记录了白奶牛的数量就可以通过全部白牛的数量-左边白牛的数量算出右边白牛的数量
    左边牛的数量-左边白牛的数量就是左边黑牛的数量了
    */

    vector<int> pre;
    int min_change = white_cow;
    int left_black = 0, left_white = 0, right_white = white_cow;
    for (size_t i = 0; i < n; i++) {
        if (a[i] == BLACK) {
            left_black++;
        } else {
            left_white++;
            right_white--;
        }
        min_change = min(min_change, left_black + right_white);
    }

    cout << min_change;
    return 0;
}


/*
Description
    农夫约翰的奶牛场有很多奶牛，奶牛有黑白两种颜色。现在奶牛们排成整齐的一列去参加镇上的游行活动。
约翰希望白色奶牛都排在前面，黑色的奶牛都排在后面。但现在队列中奶牛的颜色是混乱的，并且奶牛们都不愿意改变位置。
幸运的是，约翰有一根魔法棒，每挥舞一次魔法棒就可以改变一头奶牛的颜色。
请问，约翰至少要挥舞多少次魔法棒，才能将队列改成他希望的状态。注意，可以将所有的奶牛都变成白色，或者都变成黑色。
输入格式
    第一行一个正整数n，表示奶牛的头数。(1<=n<=200000)。
第二行n个正整数，均为1或2，1表示白色奶牛，2表示黑色奶牛。

输出格式
    一个正整数，表示挥舞魔法棒的最少次数。
输入样例
7
2 2 1 1 1 2 1

输出样例
    3
提示
    可以把1和2号奶牛变成1,7号奶牛变成2，或者全部奶牛变成1，最少需要3次。
*/
