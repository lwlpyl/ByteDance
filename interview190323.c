/**
字节跳动2019春招面试 编程题 
写一个函数，将单向链表反转 
**/

#include<stdio.h>

typedef struct{
	int data;
	struct ListNode* next;
}ListNode;

ListNode* reverse(ListNode* head){
	ListNode *p, *q, *r;
	if(head==NULL || head->next==NULL){
		return head;
	}
	p = head;
	q = p->next;
	p->next = NULL;
	while(q!=NULL){
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	return p;
}

void show(ListNode* head){
	ListNode* p;
	p = head;
	while(p!=NULL){
		printf("%d ", p->data);
		p = p->next;
	}
}

int main(){
	ListNode* head;
	ListNode* p1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* p2 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* p3 = (ListNode*)malloc(sizeof(ListNode));
	p1->data = 1;
	p2->data = 2;
	p3->data = 3;
	p1->next = p2;
	p2->next = p3;
	p3->next = NULL;
	head = p1;
	show(head);
	
	head = reverse(head);
	show(head);
		
	return 0;
}


