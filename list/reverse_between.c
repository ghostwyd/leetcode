#include <stdlib.h>
#include <stdio.h>

#include "list_node.h"

//https://leetcode-cn.com/problems/reverse-linked-list-ii/
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if (m == n) {
        return head;
    }

    int i = 1;
    struct ListNode *curr = head;
    struct ListNode *prev = NULL;
    struct ListNode *new_tail;
    struct ListNode *new_head;
    struct ListNode *next;

    while(i < m) {
        prev = curr;
        curr = curr->next;
        ++i;
    }
    new_tail = curr;
    new_head = curr;
    curr= curr->next;
    new_tail->next = NULL;
    for (;i<n; i++) {
        next = curr->next;
        curr->next = new_head;
        new_head = curr;
        curr = next;
    }
    if (prev != NULL) {
        prev->next = new_head;
    }
    new_tail->next = next;
    if (m == 1) {
        return new_head;
    }
    return head;
}

int main(void) 
{
    return EXIT_SUCCESS;
}
