#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

typedef void* datapointer;
int tos=0;
int localSize;
int value;
datapointer a[100];
char bchar[100];
int bint[100];
void createStack(int size,unsigned char t)
{
	printf(" Inside Create Stack with %d\n",t);
	switch(t){
		case 48:	
			printf("char case matched\n");			
			a[0] = (void*)calloc(size,sizeof(bchar));
			printf("Allocated memory \n");
			localSize = size;
			break;
		case 49:
			//printf("int case matched\n");	
			a[0] = (void*)calloc(size,sizeof(bint));
			//printf("Allocated memory \n");
			localSize = size;
			break;
		default:
			break;
	}
}

int push(long value,unsigned char t1)
{
	//printf("inside push function\n");
	void *temp;
	int i=0;
	if(tos==localSize)	{ printf("stack full\n");return 1;}
	else if(value==-1) { return -1;}
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
	return 1;	
}
long pop(char t)
{
	if(tos==0) { printf("stack empty\n"); return -1;}
	tos--;
	switch(t)
		{
			case '0':
				if(tos>0)	
				printf("stack not empty%c\n",bchar[tos]);
				return bchar[tos];
			case '1':
				if(tos>0)	
				printf("stack not empty%d\n",bint[tos]);	
				return bint[tos];
		}

}
