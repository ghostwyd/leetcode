#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "list_node.h"

//https://leetcode-cn.com/problems/rotate-list/description/

//给定一个链表，旋转链表，将链表每个节点向右移动k个位置，其中k是非负数。
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || k == 0) {
        return head;
    }    

    struct ListNode *cur_node = head;
    struct ListNode *forward_node = head;
    int list_len = 0;

    //get list len
    while(forward_node != NULL) {
        forward_node = forward_node->next;
        ++list_len;
    }

    int rotate_cnt = list_len - k % list_len;
    if (rotate_cnt == list_len) {
        return head;
    }

    unsigned step_count = 0;
    struct ListNode *pre_node = NULL;
    cur_node = head;
    forward_node = head;
    while (forward_node != NULL && step_count < rotate_cnt) {
        pre_node = forward_node;
        forward_node = forward_node->next;
        ++step_count;
    }
    pre_node->next = NULL;
    cur_node = forward_node;
    while (cur_node->next != NULL) {
        cur_node = cur_node->next;
    }
    cur_node->next = head;
    printf("cur_node: %d\n", forward_node->val);
    return forward_node;
}

int main(void)
{
    int k = 0;
    struct ListNode	*head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;

    struct ListNode *cur_node = head;
    for (int i = 0; i < 0; ++i) { 
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = i + 1;
        node->next = NULL;
        cur_node->next = node;
        cur_node = node;
    }
    print_list(head);
    printf("---------------------------\n");
    cur_node = rotateRight(head, k);
    print_list(cur_node);
    return 0;
}
