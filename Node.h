#ifndef _node_
#define _node_


/* function prototypes here */
	typedef struct Node
	{
		union data
		{
			char chardata;
			int intdata;
			long longData;
		} mydata;
		struct Node *next;
	}node;	

#endif
