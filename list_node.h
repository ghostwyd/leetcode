#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void print_list_check(struct ListNode *head) {
    int count = 0;
    if (head == NULL) {
        printf("node count:0\n");
        return;
    }
    struct ListNode *ptr = head->next;
    printf("%02d", head->val);
    count++;
    struct ListNode *pre = head;
    while(ptr != NULL) {
        printf(" %02d", ptr->val);
        if (pre->val> ptr->val) {
            printf("wrong!\n");
            assert(0);
        }
        pre = ptr;
        ptr = ptr->next;
        count++;
    }
    printf("\n");
    printf("node count:%d\n", count);
}

void print_list(struct ListNode *head) {
    int count = 0;
    if (head == NULL) {
        printf("node count:0\n");
        return;
    }
    struct ListNode *ptr = head;
    while (ptr != NULL) {
        printf("%02d ", ptr->val);
        ptr = ptr->next;
        ++count;
    }
    printf("\n");
    printf("node count:%d\n", count);
}
