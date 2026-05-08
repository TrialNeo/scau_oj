#include "malloc.h"
#include "stdio.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

typedef char ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

Status CreateBiTree(BiTree &T) { // 算法6.4
    // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
    // 构造二叉链表表示的二叉树T。
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
        T = NULL;
    else {
        if (!(T = (BiTNode *) malloc(sizeof(BiTNode))))
            return ERROR;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
} // CreateBiTree

// 三个可以一起来看，还是倾向于用队列做一个广度优先，算了他不给用 直接递归吧，深度优先也可
// 然后我们直接统计度为0/1/2 中的其中一个就行了,有公式可以算另外两个
// n = n0 + n1 + n2
// n0 = n2 + 1
unsigned count_dg0(BiTree &T, unsigned &total) {
    if (T == NULL) {
        return 0;
    }
    total++;
    if (!T->lchild && !T->rchild) {
        return 1 + count_dg0(T->lchild, total) + count_dg0(T->rchild, total);
    }
    return count_dg0(T->lchild, total) + count_dg0(T->rchild, total);
}


int main() // 主函数
{
    BiTree T;
    CreateBiTree(T);
    unsigned total = 0, n0 = count_dg0(T, total), n2 = n0 - 1, n1 = total - n0 - n2;
    printf("%u\n", n2);
    printf("%u\n", n1);
    printf("%u\n", n0);
} // main
