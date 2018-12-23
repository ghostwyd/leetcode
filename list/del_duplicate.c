#include <stdlib.h>
#include <stdio.h>

#include "list_node.h"

//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) {
        return head;
    }
    struct ListNode *prev = head;
    struct ListNode *cur = head->next;
    while(cur != NULL) {
        if (prev->val == cur->val) {
            prev->next = cur->next;
        } else {
            prev = cur;
        }
        cur = prev->next;

    }
    return head; 
}

//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
struct ListNode* deleteDuplicatesII(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    struct ListNode *cur = head;
    struct ListNode *new_cur = NULL;
    struct ListNode *new_head = NULL;
    int cur_value = 0;
    int cur_count = 0;
    while (cur != NULL) {
        if (cur == head) {
            cur_value = cur->val;
            cur_count = 0;
        } 
        if (cur_value == cur->val) {
            ++cur_count;
        }
        if ((cur->next == NULL || cur->next->val != cur->val)) {
            if (cur_count == 1) {
                if (new_head == NULL) {
                    new_head = cur;
                    new_cur = new_head;
                } else {
                    new_cur->next = cur;
                    new_cur = new_cur->next; 
                }
            }
            if (cur->next != NULL) {
                cur_value = cur->next->val;
                cur_count = 0;
            }
        } 
        cur = cur->next;
    }
    if (new_cur != NULL) {
        new_cur->next = NULL;
    }
    return new_head;
}

int main(void)
{

    int array[] = {1, 2, 2};
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    head->val = array[0];
    struct ListNode *pre = head;
    for (int i = 1; i < sizeof(array)/sizeof(int); ++i) {
        struct ListNode *cur = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur->val = array[i];
        cur->next = NULL;
        pre->next = cur;
        pre = cur;
    }
    print_list(deleteDuplicatesII(head));     
    return EXIT_SUCCESS;
}
