#ifndef _stack_
#define _stack_


/* function prototypes here */
	extern int tos;
	extern void createStack(int size,unsigned char myType);
	extern void push(long* value,unsigned char myType);
	extern long*pop(unsigned char myType); 

#endif
