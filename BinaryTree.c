#include "treeNode.h"
#include <stdio.h>
#include <stdlib.h>

binarytreenode* root1;
time_t t;
binarytreenode* createBinaryTree(int size)
{
	//ssrand((unsigned) time(&t));
	int i=0;
	root1 = (binarytreenode* )malloc(sizeof(binarytreenode));
	root1->lptr = 0;
	root1->rptr = 0;
	root1->mydata.intdata = rand() % 5;
	printf("Allocated Memory for root with data %d \n",root1->mydata.intdata);
	binarytreenode* p1 = root1,*parent = root1;
	while(i<size-1)
	{	
		inorder(root1);
		int myRand = rand() % 5;
//		int numberofturns=0;
		//printf("myRand== %d",myRand);
		p1 = root1;
		while(p1)
		{
			parent = p1;
			if(p1->mydata.intdata > myRand) 
			{
				p1 = p1->lptr;
			}
			else
			{
				p1 = p1->rptr;
			}
//			numberofturns++;			
		}
//		printf("number of turns === %d\n",numberofturns);
		if(parent->mydata.intdata > myRand) 
		{
			parent->lptr = (binarytreenode* )malloc(sizeof(binarytreenode));	
			parent->lptr->mydata.intdata = myRand;			
			printf("Allocated Memory for lptr with data %d \n",myRand);
			parent->lptr->lptr = 0;
			parent->lptr->rptr = 0;
		}	
		else
		{
			parent->rptr = (binarytreenode* )malloc(sizeof(binarytreenode));
			parent->rptr->mydata.intdata = myRand;			
			printf("Allocated Memory for rptr with data %d \n",myRand);
			parent->rptr->lptr = 0;
			parent->rptr->rptr = 0;
		}					
		i++;
	}
	return root1;
}

void inorder(binarytreenode* root)
{
	if(root)
	{
		if(root->lptr!=0) inorder(root->lptr);
		printf("%d  ",root->mydata.intdata);
		if(root->rptr!=0) inorder(root->rptr);
	}
}
