#include <stdio.h>
#include <stdlib.h>
#include "Node.h"


int main(int argc,char *argv[])
{
	void populateHashTable(int key2,int m2,node **hashtable2);
	void printHashTable(int m1,node *hashtable1[]);
	int m ,i,j;
	printf("Enter the number of locations in hashable \n");
	scanf("%d",&m);
	node *hashtable[m];
	
	for(i=0;i<m;i++)
	{
		hashtable[i] = 0;
	}
	for(i=1;i<argc;i++)
	{
		populateHashTable(atoi(argv[i]),m,(node**)hashtable);
	}	
	printHashTable(m,hashtable);
}

void populateHashTable(int key,int m,node **hashtable)
{
	void printHashTable(int m1,node *hashtable1[]);
	if(!hashtable[key%m])
	{
		int i=0;
		node* head = (node*)malloc(sizeof(node));
		node* p = head;
		(p->mydata).intdata = key;
		hashtable[key%m] = head;	
		i++;			
		p->next = 0;
	}
	else
	{
		printf("Created new node for %d\n",key);
		node *newNode = (node*)malloc(sizeof(node));
		(newNode->mydata).intdata = key;
		newNode->next = 0;
		node* p;
		p = hashtable[key%m];
		while((p->next)!=0)
		{
			p=p->next;
		}
		p->next = newNode;
	}	
}

void printHashTable(int m,node **hashtable)
{
	static int printHashTableCount;
	printHashTableCount++;
	int i=0;
	for(i=0;i<m;i++)
	{
		if(!hashtable[i]) printf("\n");
		else
		{
			node* p = hashtable[i];
			while((p->next)!=0)
			{
				printf("%d ",(p->mydata).intdata);
				p=p->next;
			}
			printf("%d ",(p->mydata).intdata);
		}		
		printf("\n");
	}
}
