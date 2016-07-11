#include <stdio.h>
#include <stdlib.h>
#include "treeNode.h"

int main(int argc,char*argv[])
{
	binarytreenode*;
	if(argc>1)
	{
		head = createLinkedList(atoi((const char *)argv[1]));
	}
	node *newNode = (node*)malloc(sizeof(node));
	(newNode->mydata).intdata = 20;
	newNode->next = 0;
	add(newNode);
	printList();
	return 1;
}
