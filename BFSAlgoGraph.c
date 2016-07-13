#include <stdio.h>
#include <stdlib.h>
int sizeofGraph=0;
int main(int argc,char* argv[])
{
	sizeofGraph = atoi(argv[1]);
	int levelVector[sizeofGraph];
	int newlyvisited[sizeofGraph];
	int graph[sizeofGraph][sizeofGraph];
	int crossedges[sizeofGraph*sizeofGraph][2];
	int backedges[sizeofGraph*sizeofGraph][2];
	int visited[sizeofGraph];
	int i=0,j,startnode;
	printf("Enter Start Node\n");
	scanf("%d",&startnode);
	printf("Size of Graph = %d\n",sizeofGraph);	
	for(i=0;i<sizeofGraph;i++)
	{
		for(j=0;j<sizeofGraph;j++)
		{
			graph[i][j] = rand() % 2;
			graph[j][i] = graph[i][j];
		}
		printf("\n");
	}
	for(i=0;i<sizeofGraph*sizeofGraph;i++)
	{
		crossedges[i][0] = -1;
		crossedges[i][1] = -1;
	}
	for(i=0;i<sizeofGraph*sizeofGraph;i++)
	{
		backedges[i][0] = -1;
		backedges[i][1] = -1;
	}
	for(i=0;i<sizeofGraph;i++)
	{
		visited[i]=-1;
		newlyvisited[i] = -1;
		levelVector[i]=-1;
	}
	visited[startnode] = 1;
	levelVector[startnode] = 0;
	bfs((int *)levelVector,(int *)visited,(int **)crossedges,(int **)backedges,(int **)graph,sizeofGraph,startnode,(int*)newlyvisited);
}
void printAllDataStructures(int*levelVector,int *visited,int **crossedges,int **backedges,int **graph,int size)
{
	int i=0,j=0;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{		
			printf("%d ",*((graph+i*size)+j));
		}
		printf("\n");
	}
	for(i=0;i<size*size;i++)
	{
		printf("%d %d-",*((crossedges+i*size)+0),*((crossedges+i*size)+1));
		printf("\n");
	}

	for(i=0;i<size*size;i++)
	{
		printf("%d %d--",*((backedges+i*size)+0),*((backedges+i*size)+1));
		printf("\n");
	}

	for(i=0;i<size;i++)
	{
		printf("%d %d---",*(visited+i) ,*(levelVector+i) );
		printf("\n");
	}
	return;
}
void bfs(int *levelVector,int *visited,int** crossedges,int** backedges,int** inputgraph,int size,int start,int *newlyvisited)
{
	void printAllDataStructures(int *t1,int *t2,int **t3,int **t4,int **t5,int t6);
	static int backedgecount=0,crossedgecount=0,visitedCount=0,newlyvisitedcount=0;
	int i=0,k1,k2;
	printAllDataStructures(levelVector,visited,crossedges,backedges,inputgraph,size);
	for(i=0;i<size;i++)
	{
		if(*((inputgraph+start*size)+i)==1)
		{						
			if(visited[i] ==-1)
			{
				visited[i] = 1;
				visitedCount++;
				levelVector[i] = levelVector[start]++;
				newlyvisited[newlyvisitedcount] = i;
				newlyvisitedcount++;
			}
		}
	}
	//printAllDataStructures(levelVector,visited,crossedges,backedges,inputgraph,size);
	for(k1=0;k1<size;k1++)
	{
		if(k1==start) continue;
		for(k2=0;k2<size;k2++)
		{
			if(k2==start) continue;
			if(*((inputgraph+k1*size)+k2)==1)
			{					
				if(*(levelVector+k1)==*(levelVector+k2))
				{
					*((backedges+backedgecount*size)+0)=k1;
					*((backedges+backedgecount*size)+1)=k2;
					backedgecount++;
				}
			}			
		}
	}
	printf("Entering 3 for loop---\n");
//	printAllDataStructures(levelVector,visited,crossedges,backedges,inputgraph,size);
	for(k1=0;k1<size;k1++)
	{
		if(k1==start) continue;
		for(k2=0;k2<size;k2++)
		{
			if(k2==start) continue;
			if(*((inputgraph+k1*size)+k2)==1)
			{	
				if(levelVector[k1]==(levelVector[k2]-1))
				{

					*((crossedges+crossedgecount*size)+0)=k1;
					*((crossedges+crossedgecount*size)+1)=k2;
					crossedgecount++;
				}
			}			
		}
	}

	printAllDataStructures(levelVector,visited,crossedges,backedges,inputgraph,size);
	for(i=0;i<size;i++)
	{
		if(newlyvisited[i]==-1) continue;		
		else if(newlyvisited[i]==1) 
		{
			newlyvisited[i]=0;
			bfs((int *)levelVector,(int *)visited,(int **)crossedges,(int **)backedges,(int **)inputgraph,size,i,(int*)newlyvisited);
		}
		else if(newlyvisited[i]==0)
		{
			continue;
		}
	}
}
