#include <stdlib.h>
#include <stdio.h>

//https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
   if (l1 == NULL) {
       return l2;
   }
   if (l2 == NULL) {
       return l1;
   }
   struct ListNode *head= NULL; 
   struct ListNode **chosen_node = NULL;
   struct ListNode *first_ptr = l1;
   struct ListNode *second_ptr = l2;
   struct ListNode *cur_node = NULL;
   while (first_ptr && second_ptr) {
       if (first_ptr->val < second_ptr->val) {
           chosen_node = &first_ptr;
       } else {
           chosen_node = &second_ptr;
       }
       if (!head) {
           head = *chosen_node;
           cur_node = head;
       } else {
           cur_node->next = *chosen_node;
           cur_node = cur_node->next;
       }
       *chosen_node = (*chosen_node)->next;
   }
   if (first_ptr) {
       cur_node->next = first_ptr;
   }
   if (second_ptr) {
       cur_node->next = second_ptr;
   }
   return head;
}

int main(void)
{
    return 0;
}

