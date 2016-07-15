#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(int argc,char*argv[])
{
	int isalphabet(char a);
	int priority(char input);
	int i=0,size;
	char input;
	long temp1=0,temp2=0;
	char *output,*base;
	printf("Enter the size of stack \n");
	scanf("%d",&size);
	createStack(size,'0');
//	temp1 = (long*)malloc(sizeof(long));
	output = (char*)malloc(sizeof(char)*(size+1));
	base  = output;
	*(output+size) = '\0';
	if(argc>1)
	{
		printf("%s\n",*(&argv[1]));
	}
	else
	{
		printf("argv ==  empty");
		return ;
	}
	for(i=0;i<size;i++)
	{		
		if(isalphabet(argv[1][i])!=-1)
		{
			printf("added to end of input%c\n",argv[1][i]);
			*output = argv[1][i]; 
			output++;
			printf("i==%d\n",i);
			continue;
		}
		else if(argv[1][i]=='\0') 
		{
			printf("reached end of input\n");
			return 1;
		}
		else if(push((char)pop('0'),'0')!=-1)
		{	
			temp1 = pop('0');
			*output = (char)temp1;
			output++;
			if(priority(argv[1][i])>=priority((char)temp1))	
			{
				/**output = pop('0');
				printf("Instack priority <= Incoming Proirity");
				printf( "%d %d\n",priority(input) , priority(*output)) ;
				output++;
				*/
				continue;
			}	
			else
			{
				printf("Instack priority > Incoming Proirity");
				*output = (char)pop('0');
				temp1= *output;
				output++;
				while(priority(argv[1][i])<priority(temp1))	
				{				
					if((*output=pop('0'))==-1) { break; }	
					output++;
					temp1= *output;					
				}
				
			}
			push(argv[1][i],'0');
			continue;
		}
		else 
		{
			printf("pushed %c",argv[1][i]);
			push((argv[1])[i],'0');	
		}
	}
	while((temp1=pop('0'))!=-1)
	{
		*output = (char)temp1;
		output++;
	}
	while(*base!='\0') { printf("%c",*base); base++;}	
	return 0;
}

int isalphabet(char a)
{
	if((a >= 'a') && (a<='z')) return 1;
	printf("not alphabet \n");
	return -1;	

}
int priority(char x)
{
	switch(x)
	{
		case '(': return 5;
		case ')': return 6;
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		default: return -1;
	}
	if(strcmp(&x,"++")) return 5;
	else if(strcmp(&x,"--")) return 5;
	else return 7;
}
