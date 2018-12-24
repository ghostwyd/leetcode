#include <stdio.h>
#include <stdlib.h>

#include "list_node.h"

//https://leetcode-cn.com/problems/partition-list/
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *less_ptr = NULL;
    struct ListNode *less_head = NULL;
    struct ListNode *greater_ptr = NULL;
    struct ListNode *geater_head = NULL;
    struct ListNode  *cur = head;

    while(cur != NULL) {
        if (cur->val <  x) {
            if (less_head == NULL) {
                less_head = cur;
                less_ptr = cur;
            } else {
                less_ptr->next = cur;        
                less_ptr = less_ptr->next;
            }

        } else {
            if (geater_head == NULL) {
                geater_head = cur;
                greater_ptr = cur;
            } else {
                greater_ptr->next = cur;        
                greater_ptr = greater_ptr->next;
            }
        }
        cur = cur->next;
    }

    if (less_ptr != NULL) {
        less_ptr->next = geater_head;
    }

    if (greater_ptr != NULL) {
        greater_ptr->next = NULL;
    }

    if (less_head != NULL){
        return less_head;
    }
    return geater_head;
}
