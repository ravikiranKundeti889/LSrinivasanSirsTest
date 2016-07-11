#ifndef _binarytreenode_
#define _binarytreenode_


/* function prototypes here */
	typedef struct Node
	{
		union data
		{
			char chardata;
			int intdata;
			long longData;
		} mydata;
		struct Node *lptr;
		struct Node *rptr;
	}binarytreenode;	

#endif
