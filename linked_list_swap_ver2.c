#include <stdio.h>
#include <stdlib.h>
typedef struct fuckgg {
	int val;
	struct fuckgg *next;
}Node, *NodePtr;
void print_all(NodePtr head) {
	while(head) {
		if(!head->next) {
			printf("%d", head->val);
			break;
		}
		printf("%d->", head->val);
		head = head->next;
	}
	puts("");
}
NodePtr create_list(int i, int n) {
	NodePtr head, tail, p;
	head=tail=(NodePtr)malloc(sizeof(Node));
	for(i;i<=n;i++) {
		tail->next = (NodePtr)malloc(sizeof(Node));
		tail = tail->next;
		tail->val = i;
	}
	tail->next = NULL;
	p = head;
	head = head->next;
	free(p);
	return head;
}
NodePtr swap(NodePtr head, NodePtr a, NodePtr b) {
	NodePtr dummyHead = (NodePtr)malloc(sizeof(Node));
	dummyHead->next = head;
	NodePtr pre_a = dummyHead, pre_b = dummyHead;
	while(pre_a->next != a) pre_a = pre_a->next;
	while(pre_b->next != b) pre_b = pre_b->next;
	if( head == NULL || !pre_a->next || !pre_b->next || a == b ) return NULL;
		pre_a->next = b;
		pre_b->next = a;
		pre_b = b->next;
		b->next = a->next;
		a->next = pre_b;
	head = dummyHead->next;
	free(dummyHead);
	return head;
}
void main(void) {
	printf("[+] Creating a Linked-list 1~5.\n");
	NodePtr testData = create_list(1,5);
	print_all(testData);
	puts("Let me swap it adjacently! swap(3,4)");
	swap(testData,testData->next->next,testData->next->next->next);
	print_all(testData);
	puts("Let me change between head and tail. swap(1,5)");
	NodePtr tail=testData;
	while(tail->next) tail = tail->next;
	print_all(swap(testData,testData,tail));
}
