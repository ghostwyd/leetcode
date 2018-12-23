#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "tree_node.h"

//https://leetcode-cn.com/problems/same-tree/description/
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL  && q == NULL)  {
        return true;
    }
    if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
        return false;
    }
    if (p->val !=  q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(void)
{
    return 0;
}
