#include "polyNode.h"
#include <stdio.h>
#include <stdlib.h>

polynode* createLinkedList(int size)
{
	polynode* p=(polynode* )malloc(sizeof(polynode)),*q=0;		
	int i=1;
	polynode *head = p;
	while(i<size)
	{
		if((rand() % 4) <2);		
		{
			q = (polynode* )malloc(sizeof(polynode));
			q->mydata.coefficient = i % (size) * 3 + i -1;
			q->mydata.degree = i % (size);	
			p->next = q;	
			p=q;
		}
		i++;
	}
	p->next = 0;
	return head;
}
void printList(polynode*p)
{
	while(p!=0)
	{
		printf("%d %d --- ",p->mydata.coefficient,p->mydata.degree);
		p=p->next;
	}
	printf("\n");
}
polynode* add(polynode *a,polynode *b)
{	
	polynode *ahead = a,*bhead=b,*temp,*itra,*itrb;
	while(a->next!=0 && b->next!=0)
	{
		if(a->mydata.degree > b->mydata.degree) 
		{
			printf("Degree of a > b \n");
			itra = a;
			while(a->next!=0 && a->mydata.degree > b->mydata.degree){
				itra = a;
				a = a->next;
			}
			if(a->next == 0 || a->mydata.degree <= b->mydata.degree)
			{
				a = itra->next;
				itra->next = b;
				continue;
			}
		}
		else if (b->mydata.degree > a->mydata.degree)
		{
			printf("Degree of a < b \n");
			while(b->next!=0 && b->mydata.degree > a->mydata.degree)
			{
				itrb = b;
				b = b->next;
			}	
			if(b->next == 0 || b->mydata.degree <= a->mydata.degree)
			{
				b = itrb->next;
				itrb->next = a;
				continue;
			}
		}
		else
		{
			printf("Degrees are equal %d %d\n",a->mydata.degree,b->mydata.degree);
			printf("Coefficients are %d %d\n",a->mydata.coefficient , b->mydata.coefficient);
			a->mydata.coefficient =  a->mydata.coefficient + b->mydata.coefficient;
			polynode *temp = b->next;
			deleteNode(b,&bhead);
			b = temp;	
			bhead = b;	
			a=a->next;
			
			printf("Degrees are  %d %d\n",a->mydata.degree,b->mydata.degree);
			printf("Coefficients are %d %d\n",a->mydata.coefficient , b->mydata.coefficient);
		}
		printList(ahead);
		printList(bhead);
		printf("End Of While iteration \n");
	}	
	{
		if(a->mydata.degree > b->mydata.degree) 
		{
			printf("Degree of a > b \n");
			do{
				a = a->next;
			}while(a->next!=0 && a->mydata.degree > b->mydata.degree)	;
			if(a->next == 0 || a->mydata.degree <= b->mydata.degree)
				return;
		}
		else if (b->mydata.degree > a->mydata.degree)
		{
			printf("Degree of a < b \n");
			do{
				b = b->next;
			}while(b->next!=0 && b->mydata.degree > a->mydata.degree)	;
			if(b->next == 0 || b->mydata.degree <= a->mydata.degree)
				return;
		}
		else
		{
			printf("Degrees are equal \n");
			a->mydata.coefficient =  a->mydata.coefficient + b->mydata.coefficient;
			polynode *temp = b->next;
			deleteNode(b,&bhead);
			b = temp;	
			bhead = b;	
		}
		printList(ahead);
		printList(bhead);
	}
	printList(ahead);	
	return ahead;
}
void deleteNode(polynode *input,polynode **head)
{	
	printf("Inside Delete Node\n");
	polynode* p = *head;
	if(input != *head) 
	{
		printf("Inside if of Delete Node %p %p\n");
		while(p->next!=input) p = p->next;
		p->next = input->next;
	}
	else 
	{
		printf("Inside else of Delete Node\n");
		p = *head;	
		*head = (*head)->next;
		free(p);
		return;
	}
	free(input);
	printList(*head);
}
