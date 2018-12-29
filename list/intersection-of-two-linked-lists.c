#include <stdlib.h>
#include <stdio.h>

#include "list_node.h"

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

struct ListNode *getIntersectionNodeII(struct ListNode *headA, struct ListNode *headB) {
    int len1 = 0;
    int len2 = 0;
    int sub = 0;
    struct ListNode *cur1 = headA;
    struct ListNode *cur2 = headB;
    while (cur1 != NULL) {
        ++len1;
        cur1 = cur1->next;
    }
    while (cur2 != NULL) {
        ++len2;
        cur2 = cur2->next;
    }
    if (len1 > len2) {
        sub = len1 - len2;
        cur1 = headA;
        cur2 = headB;
    } else {
       sub = len2 - len1; 
       cur1 = headB;
       cur2 = headA;
    }
    
    while(sub > 0) {
        cur1 = cur1->next;
        sub--;
    }
    while(cur1 != NULL && cur2 != NULL) {
        if (cur1 == cur2) {
            return cur1;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return NULL;
}
