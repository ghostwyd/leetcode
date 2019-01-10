#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "tree_node.h"

bool isValidBST(struct TreeNode* root) {
    if (!root) {
        return true;
    }
    if (root->left != NULL && root->val <= root->left->val) {
        return false;
    }
    if (root->right != NULL && root->val >= root->right->val) {
        return false;
    }
    return isValidBST(root->left) && isValidBST(root->right);
    
}
