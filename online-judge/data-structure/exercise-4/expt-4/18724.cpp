#include <iostream>
using namespace std;


void postorder(string pre, string in) {
    if (pre.empty()) {
        return;
    }
    char root = pre[0];
    int pos = in.find(root);
    postorder(pre.substr(1, pos), in.substr(0, pos));
    postorder(pre.substr(pos + 1), in.substr(pos + 1));
    cout << root;
}

int main(int argc, char const *argv[]) {
    string pre, in;
    cin >> pre >> in;
    postorder(pre, in);
    return 0;
}


/*
Description
二叉树的三种遍历都可以通过递归实现。
如果我们知道一棵二叉树的先序和中序序列，可以用递归的方法求后序遍历序列。



输入格式
两行，第一行一个字符串，表示树的先序遍历，第二行一个字符串，表示树的中序遍历。
树的结点一律用小写字母表示,且字符串长度不超过30。


输出格式
一个字符串，树的后序序列。


输入样例
abcde
bcade


输出样例
cbeda


*/
