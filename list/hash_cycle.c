#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "list_node.h"

//https://leetcode-cn.com/problems/linked-list-cycle/comments/

bool hasCycle(struct ListNode *head) {
    struct ListNode *slow_ptr = head;
    struct ListNode *fast_ptr = head;
    while(fast_ptr != NULL && slow_ptr != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
        if (fast_ptr == NULL || fast_ptr->next == NULL) {
            return false;
        }
        fast_ptr = fast_ptr->next;
        if (fast_ptr == slow_ptr) {
            return true;
        }
    }
    return false;
}
int main(void)
{
    return EXIT_SUCCESS;
}
