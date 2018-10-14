#include <stdlib.h>
#include <stdio.h>

#include "tree_node.h"

//https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int stack_size = 64;
    struct TreeNode **stack = (struct TreeNode**)malloc(stack_size*sizeof(struct TreeNode*));

    int top_index = 0;
    int array_size = 64;
    int *array = (int*)malloc(sizeof(int)*array_size); 
    *returnSize = 0;
    
    struct TreeNode *cur_node = root;
    while (cur_node != NULL || top_index != 0) {
        if (cur_node != NULL) {
            if (top_index == stack_size) {
                stack_size += 64;
                stack = (struct TreeNode**)realloc(stack, stack_size*sizeof(struct TreeNode*));
            }
            stack[top_index] = cur_node;
            ++top_index;
            cur_node = cur_node->left;
            while(cur_node != NULL) {
                if (stack_size == top_index) {
                    stack_size += 64;
                    stack = (struct TreeNode**)realloc(stack, stack_size*sizeof(struct TreeNode*));
                }
                stack[top_index] = cur_node;
                ++top_index;
                cur_node = cur_node->left;
            }
        }

        //save cur_node node
        cur_node = stack[top_index-1];
        if (*returnSize == array_size) {
            array_size += 64;
            array = (int*)realloc(array, sizeof(int)*array_size);
        }
        array[*returnSize] = cur_node->val;
        ++(*returnSize);

        top_index = top_index - 1;
        cur_node = cur_node->right;

    }
    free(stack);

    array = (int*)realloc(array, sizeof(int)*(*returnSize));
    return array;

}

int main(void)
{
    return 0;
}
