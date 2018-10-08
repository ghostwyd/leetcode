#include <stdlib.h>
#include <stdio.h>

#include "list_node.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *forward = head;
    struct ListNode *curr_node = head;
    struct ListNode *pre_node = NULL;
    int index = 0;
    while (index < n && forward != NULL) {
        forward = forward->next;
        ++index;
    }
    if (forward == NULL) {
        head = head->next;
        return head;
    }
    while (forward != NULL) {
        forward = forward->next;
        pre_node = curr_node;
        curr_node = curr_node->next;
    }
    if (pre_node != NULL) {
        pre_node->next = curr_node->next;
    } else {
        head = head->next;
    }
    return head;
}

int main(void)
{
    return 0;
}
