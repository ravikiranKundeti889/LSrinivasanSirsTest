#include <stdio.h>
#include <stdlib.h>
#include "polyNode.h"

int main(int argc,char*argv[])
{
	polynode *astart,*bstart;
	if(argc>1)
	{
		printList(astart= createLinkedList(atoi((const char *)argv[1])));		 
	}	
	printList(bstart = createLinkedList(atoi((const char *)argv[2])));
	printList(add(astart,bstart));
	return 1;
}
