#include <stdlib.h>
#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
}; 

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	if (k == 1 || head == NULL) {
		return head;
	} 

	struct ListNode *new_head = NULL;
	struct ListNode *pre_node = head;
	struct ListNode *cur_node = head->next;
	struct ListNode *cur_head = head;
	int first = 1;

	while (1) {
		for (int i = 0 ; i < (k-1); ++i) {
			if  (cur_node == NULL) {
				break;
			}
			pre_node->next = cur_node->next;		
			cur_node->next = cur_head;
			cur_head = cur_node;	
			pre_node = cur_node;
			cur_node = pre_node->next;
		}
		if (first) {
			new_head = cur_head;
			first = 0;
		}
		if (cur_node == NULL) {
			break;
		}
		cur_head = cur_node;
		pre_node = cur_node;
		cur_node = cur_node->next;
	}
	return new_head;
}

void print_list(struct ListNode *head) {
	if (head == NULL) {
		return;
	}
	struct ListNode *ptr = head;
	while (ptr != NULL) {
		printf("%d\n", ptr->val);
		ptr = ptr->next;
	}
}

int main(void) {
	int item_count_in_group = 3;
	struct ListNode	*head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->val = 0;
	head->next = NULL;

	struct ListNode *cur_node = head;
        for (int i = 0; i < 12; ++i) { 
		struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->val = i + 1;
		node->next = NULL;
		cur_node->next = node;
		cur_node = node;
	}
	print_list(head);
	struct ListNode *new_head = reverseKGroup(head, item_count_in_group);
	print_list(new_head);
	return EXIT_SUCCESS;
}
