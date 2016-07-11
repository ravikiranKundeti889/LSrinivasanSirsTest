#include <stdio.h>
#include <stdlib.h>

int front,rear;
int main(int argc , char*argv[])
{
	void printCurrentQueue(int a,int *b);
	int enQueue(int  c,int *a,int b );
	int deQueue(int *a,int b );
	int queue[100],size1=10,i;
	front = -1;
	rear = 0;
	for(i=0;i<11;i++)
		enQueue(i,queue,size1);
	printCurrentQueue(size1,queue);
	for(i=0;i<5;i++)
		deQueue(queue,size1);
	printCurrentQueue(size1,queue);
	return 1;
}

int enQueue(int a ,int* queuePtr,int size)
{
	if((rear==front)) { printf("\ncircular queue full\n");return -1; }
	if(front == -1 ) front == 0;
	*(queuePtr+rear) = a;
	rear = (rear + 1)%size;
//	printCurrentQueue(size,queuePtr);
}
int deQueue(int *queuePtr,int size)
{	
	if(front!=0 && front==rear) printf("\ncircular queue empty\n");
	front=(front+1)%size;
	//printCurrentQueue(size,queuePtr);
	return *(queuePtr+front-1)	;
}
void printCurrentQueue(int size,int *queuePtr)
{
	int i;
	if(front==-1 ) printf("\ncircular queue empty from printCurrentQueue\n");
	i = front;
	do{
		printf("%d ",*(queuePtr+i));
		i++;
	}while((i%size)>rear);
}
