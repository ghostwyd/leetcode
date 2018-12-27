#include <stdlib.h>
#include <stdio.h>

#include "list_node.h"

struct ListNode* reverse(struct ListNode* head)
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
//https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
   struct ListNode *a = reverse(headA); 
   struct ListNode *b = reverse(headB); 
   
   struct ListNode *common_ptr = NULL;
   struct ListNode *cur_a = a;
   struct ListNode *cur_b = b;

   while (cur_a == cur_b && cur_a != NULL) {
       common_ptr = cur_a;
       cur_a = cur_a->next;
       cur_b = cur_b->next;
   }
   reverse(a);
   reverse(b);
   return common_ptr;
}
