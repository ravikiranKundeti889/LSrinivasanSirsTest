#ifndef _node_
#define _node_


/* function prototypes here */
	typedef struct myPolyNode
	{
		struct data
		{
			int coefficient;
			int degree;
		} mydata;
		struct myPolyNode *next;
	}polynode;	

#endif
