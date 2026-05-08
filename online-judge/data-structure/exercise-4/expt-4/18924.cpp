#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
map<int, unsigned> memo{{1, 0}};
map<unsigned, unsigned> m_count{{0, 1}};


// 我们不一定要把这么一颗树构造出来，我们只需要把每个节点对应的每一层的数量统计出来就行了
// 怎么说呢 比如说我们要插入一个新的节点N 我们先去找N的父节点在哪一层，比如说父节点在第0层，
// 那么这个子节点N就应该在第0+1=1层，这时候第1层的节点数应该+1
// 现在再把 子节点N对应第一层的关系存起来复用就行了

int main(int argc, char const *argv[]) {
    unsigned n = 0;
    unsigned m_max = 1; // 记录最大，免得最后再找了
    int x = 0, y = 0;
    scanf("%u", &n);
    // n-1是因为有这个根节点
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &x, &y);
        unsigned dp = memo[x] + 1;
        memo[y] = dp;
        m_max = max(m_max, ++m_count[dp]);
    }
    printf("%u\n", m_max);
    return 0;
}


/*
Description
二叉树的宽度指的是具有节点数目最多的那一层的节点个数。
          1
         / \
        2   3
       /
      4
答案为2, 第二层节点数最多，为2个节点。



输入格式
共n行。
第一行一个整数n，表示有n个结点，编号为1至n,结点1为树根。（1<=n<=50）
第二行至第n行，每行有两个整数x和y，表示在二叉树中x为y的父节点。x第一次出现时y为左孩子


输出格式
输出二叉树的宽度。


输入样例
5
1 2
1 3
2 4
2 5


输出样例
2
*/
