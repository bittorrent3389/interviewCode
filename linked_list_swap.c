#include <stdio.h>
#include <stdlib.h>
#define adj(a,b)   (a)->next = (b)->next; \
		     		(b)->next = pre_##b; \
					pre_##a->next = (b);
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
	//Here we consider the 0 node, 1 node, 2 nodes and same node.
	if( head == NULL || !pre_a->next || !pre_b->next || a == b ) return NULL;
		if(a->next == b) { //For swaping the adjacent 2 nodes
			adj(a,b)
		}
		else if(b->next == a) {
			adj(b,a)
		}
		else { //For n ( >= 3  ) nodes
	        pre_a->next = b;
			NodePtr b_next = b->next;
			b->next = a->next;
			pre_b->next = a;
			a->next = b_next;
		}
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
