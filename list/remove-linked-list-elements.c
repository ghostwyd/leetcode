#include <stdlib.h>
#include <stdio.h>

#include "list_node.h"

//https://leetcode-cn.com/problems/remove-linked-list-elements/
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *new_header = NULL;
    struct ListNode *new_cur = NULL;
    struct ListNode *cur = head;

    while (cur != NULL) {
        if (cur->val != val) {
            if (new_cur != NULL) {
                new_cur->next = cur;
                new_cur = cur;
            } else {
                new_header = new_cur = cur;
            }
        }
        cur = cur->next;
    }
    if (new_cur != NULL) {
        new_cur->next = NULL;
    }
    return new_header;
}
