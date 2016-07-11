#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

node* head;
node* createLinkedList(int size)
{
	int i=0;
	head = (node* )malloc(sizeof(node));
	node* p = head;
	node* p1 = head;
	while(i<=(size-2))
	{
		p->mydata.intdata = 10;
		p->next = (node* )malloc(sizeof(node));
		p=p->next;
		i++;
	}
	p->mydata.intdata = 10;
	p->next = 0;
	return head;
}
void printList()
{
	node* p = head;
	while(p!=0)
	{
		printf("%d ",p->mydata.intdata);
		p=p->next;
	}
}
node* add(node *a)
{
	node* p = head;
	while((p->next)!=0)
	{
		p=p->next;
	}
	p->next = a;
	return head;
}
void deleteNode(node *input)
{
	node* p = head;
	while((p->next)++!=input);
	p->next = input->next;	
	free(p);
}
