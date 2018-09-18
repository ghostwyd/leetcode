#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

#include  "list_node.h"

//extern void print_list_check(ListNode *head);

/*
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 */

//第一种思路：两个链表合并，第一个链表和第二个链表合并，新链表和第三个链表合并，以此类推……
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

    if (listsSize == 0) {
        return NULL;
    }
    struct ListNode *head = lists[0];
    struct ListNode **chosen_node;
    for (int i = 1; i < listsSize; ++i) {
        /*if (lists[i] == NULL) {
            continue;
        }*/
	struct ListNode *first_ptr = head;
	struct ListNode *second_ptr = lists[i];  		
	head = NULL;
	struct ListNode *cur_node = NULL;

	while(first_ptr && second_ptr) {
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
        chosen_node = NULL;
        if (first_ptr) {
            chosen_node = &first_ptr;
        }
        if (second_ptr) {
            chosen_node = &second_ptr;
        }
        if(!chosen_node) {
            continue;
        }
        
        if (head == NULL) {
            head = *chosen_node;
        } else {
            cur_node->next = *chosen_node;
        }
    }
    return  head; 
}

int main(void)
{
    srand(time(NULL));

    const int list_size = 3;
    struct ListNode *lists[list_size];
    int count = 0;

    for (int i = 0; i < list_size; ++i) {
        if (i == 0) {
            lists[0] = NULL;
            continue;
        }
        int start_value = rand() % 21;
        struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode)); 
        count++;
        assert(head != NULL);
        head->val = start_value;
        struct ListNode *cur_node = head;
        for (int j = 0; j < rand()%10 + 10; ++j) {
            struct ListNode *node= (struct ListNode*)malloc(sizeof(struct ListNode)); 
            assert(head != NULL);

            count++;
            node->next = NULL;
            node->val = ++start_value;

            cur_node->next = node;
            cur_node = node; 
        }
        lists[i] = head;
        print_list(head);
    }
    printf("--------------------\n"); 
    printf("node count:%d\n", count);

    struct ListNode *new_head = mergeKLists(lists, list_size);
    print_list_check(new_head);
    return 0;
}
