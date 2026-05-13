#include <queue>
#include "AVLTree.h"

// 利用广度优先去计算，因为是AVL层数比较低
unsigned AVLTree::count_leaves() {
    if (!this->root) {
        return 0;
    }
    queue<AVLNode> q;
    q.push(this->root);
    AVLNode curr;
    unsigned count = 0;
    while (!q.empty()) {
        AVLNode curr = q.front();
        q.pop();
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
        if (!curr->left && !curr->right) {
            count++;
        }
    }
    return count;
}
