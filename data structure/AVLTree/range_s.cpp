// 这个是使用栈进行的遍历

#include <stack>
#include "AVLTree.h"

#define left 0 // 下一步访问左子树
#define right 1 // 下一步访问右子树
#define leave 2 // 下一步弹出

// 利用双栈实现
vector<int> AVLTree::traversal_preorder_s() {
    vector<int> arr;
    AVLNode curr;
    stack<AVLNode> s_node;
    stack<char> s_op;
    s_node.push(this->root);
    s_op.push(left);
    while (s_node.top() != nullptr || curr != nullptr) {
        curr = s_node.top();
        arr.push_back(curr->key);
        char op = s_op.top();
        s_op.pop();
        switch (op) {
            case left:
                
                break;
            case right:

                break;
            case leave:
            
            break;
        }
    }
}
