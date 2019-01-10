#include <stdlib.h>
#include <stdio.h>

#include "list_node.h"

struct ListNode* reverseII(struct ListNode* head)
{
    if (!head || head->next == NULL) {
        return head;
    }
    struct ListNode *new_head = head; 
    struct ListNode *cur = head->next;
    new_head->next = NULL;
    while (cur != NULL) {
        struct ListNode *tmp = cur->next;
        cur->next = new_head;
        new_head = cur;
        cur = tmp;
    }
    return new_head;
}

void reorderList(struct ListNode* head) {
    if (!head || head->next == NULL) {
        return;
    }
    struct ListNode *first = head;        
    struct ListNode *second = head->next;        
    struct ListNode *new_header;
    struct ListNode *first_tail = NULL;
    while(first != NULL && second != NULL) {
        printf("first:%d, second:%d\n", first->val, second->val);
        first_tail = first;
        first = first->next;
        second = second->next;
        if (second != NULL && second->next != NULL) {
            second = second->next;
        }
    }

    new_header = first; 
    first_tail->next = NULL;
    new_header = reverseII(new_header);
    printf("%d\n", first->val);
    first = head;
    second = new_header;
    while (first && second) {
        struct ListNode *tmp1 = first->next;
        struct ListNode *tmp2 = second->next;
        first->next = second;
        second->next = tmp1; 
        second = tmp2;
        first = tmp1; 
    }
     
}

int main(void) 
{
    struct ListNode *header = (struct ListNode*)malloc(sizeof(struct ListNode));
    header->val = 1;
    struct ListNode  *cur = header;
    for (int i = 2; i < 3; ++i) {
        struct ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = i;
        tmp->next = NULL;
        cur->next = tmp;
        cur = cur->next;
    }
    reorderList(header);
    print_list(header);
    return 0;
}
