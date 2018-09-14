#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

typedef struct ListNode{
	int data;
	struct ListNode *next;
}ListNode;

void print_list(ListNode *head);

/*
* 需求：给定一个链表，链表索引的偶数位从小到大排序，奇数位从大到小排序，
* 要求将整个链表按照从小到大的顺序排列
*返回值：重新排列后的链表头结点的地址
*/
ListNode* resort_list(ListNode *head) {
	if  (!head || !head->next) {
		return head;
	}

	ListNode *odd_head = NULL;
	ListNode *tmp_ptr = head->next;
	ListNode *pre_node = head;

	while(tmp_ptr != NULL) {
		//remove node from list
		pre_node->next = tmp_ptr->next;			
		//add to head of odd list
		tmp_ptr->next = odd_head;
		odd_head = tmp_ptr;
		//judge if travel to the end
		tmp_ptr = pre_node->next;
		if (tmp_ptr->next == NULL) {
			break;
		}
		tmp_ptr = tmp_ptr->next;
		pre_node = pre_node->next;
	}

	ListNode *odd_ptr = odd_head;
	ListNode *even_ptr = head;
	ListNode *final_ptr = NULL;
	ListNode *final_head = NULL;
	if (odd_ptr->data < even_ptr->data) {
		final_head = odd_ptr;
		odd_ptr = odd_ptr->next;
	} else {
		final_head = even_ptr;
		even_ptr = even_ptr->next;
	}
	final_ptr = final_head;
	final_ptr->next = NULL;
	
	while (odd_ptr && even_ptr) {
		if (odd_ptr->data > even_ptr->data) {
		    	final_ptr->next = even_ptr;
			even_ptr = even_ptr->next;
						
		} else {
		    	final_ptr->next = odd_ptr;
			odd_ptr = odd_ptr->next;
		} 
		final_ptr = final_ptr->next;
	}

        if(odd_ptr != NULL) {
		final_ptr->next = odd_ptr;
	}
	if (even_ptr != NULL) {
		final_ptr->next = even_ptr;
	}
	return final_head;
}

void print_list(ListNode *head) {
	if (head == NULL) {
		return;
	}
	ListNode *ptr = head->next;
	printf("%d\n", head->data);
	ListNode *pre = head;
	while(ptr != NULL) {
		printf("%d\n", ptr->data);
		if (pre->data > ptr->data) {
			printf("wrong!\n");
			assert(0);
		}
		pre = ptr;
		ptr = ptr->next;
	}
}

int main(void) {

	ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	head->next = NULL;
	head->data = 0;
	ListNode *ptr = head;

	int increase = 0;
	int max = 10000;
	for (int i = 0; i < max; ++i) {
	    	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
		if (increase) {
			node->data = i + 30;
		} else {
			node->data = 10 - i;
		}
		ptr->next = node;
		node->next = NULL;
		increase = 1 - increase;
		ptr = ptr->next;
	}
		
	ListNode *new_head = resort_list(head);
	print_list(new_head);
	return EXIT_SUCCESS;
}
