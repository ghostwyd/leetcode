#include <stdio.h>
#include <stdlib.h>

#include "list_node.h"

//https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
