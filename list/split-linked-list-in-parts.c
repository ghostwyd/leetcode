#include <stdlib.h>
#include <stdio.h>

#include "list_node.h"

//https://leetcode-cn.com/problems/split-linked-list-in-parts/
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize) {
    struct ListNode **split_array = (struct ListNode**)malloc(sizeof(struct ListNode*)*k); 
    int len = 0;
    struct ListNode *cur = root;
    struct ListNode *prev;
    while (cur != NULL) {
        cur = cur->next;
        ++len;
    }

    int left = len % k;
    int step = len / k; 
    cur = root;
    for (int i = 0; i < k; ++i) {
        if (!cur) {
            split_array[i] = NULL;
            continue;
        }
        split_array[i] = NULL; 
        int len = i < left ? step+1 : step;
        for (int j = 0; j < len; ++j) {
            if (j == 0) {
                split_array[i] = cur;
            }
            prev = cur;
            cur = cur->next;
        }
        prev->next = NULL;
    }
    if (returnSize) {
        *returnSize = k;
    }
    return split_array;
}
