#include <stdlib.h>
#include <stdio.h>

#include "list_node.h"

//https://leetcode-cn.com/problems/odd-even-linked-list/
struct ListNode* oddEvenList(struct ListNode* head) {
    if (!head) {
        return head;
    }

    struct ListNode *even  = NULL;
    struct ListNode *even_head  = NULL;
    struct ListNode *cur = head;

    while (cur != NULL && cur->next != NULL) {
        if (even == NULL) {
            even_head = cur->next;
            even = even_head;
        } else {
            even->next = cur->next;
            even = even->next;
        }
        cur->next = cur->next->next;
        if (cur->next == NULL) {
            break;
        }
        cur = cur->next;
    }
    if (even != NULL) {
        even->next = NULL;
    }
    cur->next = even_head;
    return head;     
}
