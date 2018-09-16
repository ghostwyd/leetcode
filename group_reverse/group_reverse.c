#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct ListNode {
	int val;
	struct ListNode *next;
}; 

void print_list(struct ListNode *head);

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	if (k == 1 || head == NULL) {
		return head;
	} 

	struct ListNode *new_head = head;
	struct ListNode *pre_node = head;
	struct ListNode *cur_node = head->next;
	struct ListNode *cur_head = head;
	struct ListNode *last_group_tail = NULL;
	int first = 1;

	while (1) {
		struct ListNode *tmp_node = cur_node;
		int length_enough = 1;

		for (int i =0; i < (k-1); ++i) {
			if (tmp_node == NULL) {
				length_enough = 0;
				break;
			}
			tmp_node = tmp_node->next;
		}
		if (!length_enough) {
			break;
		}
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

void print_list(struct ListNode *head) {
	if (head == NULL) {
		return;
	}
	struct ListNode *ptr = head;
	while (ptr != NULL) {
		printf("%02d ", ptr->val);
		ptr = ptr->next;
	}
	printf("\n");
}

int main(void) {
	int item_count_in_group = 4;
	struct ListNode	*head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->val = 0;
	head->next = NULL;

	struct ListNode *cur_node = head;
        for (int i = 0; i < 30; ++i) { 
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
