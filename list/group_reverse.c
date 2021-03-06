#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include "list_node.h"

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (k <= 0) {
        return head;
    }

    struct ListNode *tmp_node = head;
    int list_len = 0;
    while(tmp_node != NULL)	{
        ++list_len;
        tmp_node = tmp_node->next;
    }
    int group_count = list_len / k; 	

    struct ListNode *new_head = head;
    struct ListNode *pre_node = head;
    struct ListNode *cur_node = head->next;
    struct ListNode *cur_head = head;
    struct ListNode *last_group_tail = NULL;
    int first = 1;

    for (int j =0; j < group_count; ++j) {
        for (int i = 0 ; i < (k-1) && cur_node != NULL; ++i) {
            pre_node->next = cur_node->next;		
            cur_node->next = cur_head;
            cur_head = cur_node;	
            cur_node = pre_node->next;
        }
        if (first) {
            new_head = cur_head;
            first = 0;
        }
        if (last_group_tail != NULL) {
            last_group_tail->next = cur_head;
        }
        last_group_tail = pre_node;
        if (cur_node == NULL) {
            break;
        }
        cur_head = cur_node;
        pre_node = cur_node;
        cur_node = cur_node->next;
    }
    return new_head;
}

int main(void) {
    int item_count_in_group = 4;
    struct ListNode	*head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;

    struct ListNode *cur_node = head;
    for (int i = 0; i < 27; ++i) { 
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = i + 1;
        node->next = NULL;
        cur_node->next = node;
        cur_node = node;
    }
    struct ListNode *new_head = reverseKGroup(head, item_count_in_group);
    assert(new_head != NULL);
    print_list(new_head);
    return EXIT_SUCCESS;
}
