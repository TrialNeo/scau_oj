#include <iostream>
#include <vector>
using namespace std;

typedef struct Node {
    int parent;
    int left;
    int right;
} tree;
int ans = 0;

void scan_tree(vector<tree> &arr) {
    int q, p;
    for (size_t i = 1; i < arr.size(); i++) {
        scanf("%d %d", &p, &q);
        if (!arr[p].left) {
            arr[p].left = q;
        } else {
            arr[p].right = q;
        }
        arr[q].parent = p;
    }
}


unsigned find_root(vector<tree> &arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i].parent == 0) {
            return i;
        }
    }
    return 0;
}

// 获取树深度
unsigned get_deep(vector<tree> &arr, unsigned root) {
    if (root == 0) {
        return 0;
    }
    int L = get_deep(arr, arr[root].left);
    int R = get_deep(arr, arr[root].right);
    if (L + R > ans) {
        ans = L + R;
    }
    return max(L, R) + 1;
}


// 先构造再深度优先遍历即可
int main(int argc, char const *argv[]) {
    unsigned n = 0;
    scanf("%u", &n);
    vector<tree> arr(n + 1, {0, 0, 0});
    scan_tree(arr);
    unsigned root = find_root(arr);
    get_deep(arr, root);
    printf("%u\n", ans);
    return 0;
}

/*
18923 二叉树的直径
时间限制:1000MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC

Description
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
          1
         / \
        2   3
       / \
      4   5
答案为3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。



输入格式
共n行。
第一行一个整数n，表示有n个结点，编号为1至n。
第二行至第n行，每行有两个整数x和y，表示在二叉树中x为y的父节点。x第一次出现时y为左孩子


输出格式
输出二叉树的直径。


输入样例
5
1 2
1 3
2 4
2 5


输出样例
3
*/
