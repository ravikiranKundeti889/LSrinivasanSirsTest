#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

typedef void* datapointer;
int tos=0;
int localSize=0;
int value;
datapointer a[100];
char bchar[100];
int bint[100];
void createStack(int size,unsigned char t)
{
	printf(" Inside Create Stack with %d\n",t);
	switch(t){
		case 49:	
			printf("char case matched\n");			
			a[0] = (void*)calloc(size,sizeof(bchar));
			printf("Allocated memory \n");
			localSize = size;
			break;
		case 50:
			//printf("int case matched\n");	
			a[0] = (void*)calloc(size,sizeof(bint));
			//printf("Allocated memory \n");
			localSize = size;
			break;
		default:
			break;
	}
}

void push(long*value,unsigned char t1)
{
	//printf("inside push function\n");
	void *temp;
	int i=0;
	if(tos == localSize)	{ printf("stack full\n");return;}
	else 
	{
		switch(t1)
		{
			case '0':
				//printf("trying to push %1s\n",*value);
				bchar[tos] = value;
				//printf("current element @tos == %1s\n",bchar[tos]);
				/*for(i=0;i<=tos;i++)
					//printf("%1s\n",bchar[i]);
				*/
				break;
			case '1':	
				//printf("trying to push %d\n",value);
				bint[tos] = value;
				//printf("current element @tos == %d\n",bint[tos]);
				/*for(i=0;i<=tos;i++)
					//printf("%d\n",bint[i]);
				*/
				break;
		}
		tos++;

	}
	return;	
}
long* pop(unsigned char t)
{
	if(tos==0) { printf("stack empty\n"); return -1;}
	tos--;
	switch(t)
		{
			case '0':	
				return bchar[tos];
				break;
			case '1':
				return bint[tos];
				break;
		}

}
