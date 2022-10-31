//Check if there exists a path from src to dest using BFS

#include<stdio.h>
#define MAX 10

void createGraph(int adj[MAX][MAX],int n);
int checkPath(int adj[MAX][MAX],int n,int visited[MAX],int src,int dest);
int main()
{
	int n;
	int adj[MAX][MAX];
	int visited[MAX]={0};
	int src,dest;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter adjacency info\n");
	createGraph(adj,n);
	
	printf("Enter the source & dest vertex\n");
	scanf("%d%d",&src,&dest);
	
	if(checkPath(adj,n,visited,src,dest))
		printf("There exists a path from %d to %d\n",src,dest);
	else
		printf("There exists no path from %d to %d\n",src,dest);
}
void createGraph(int adj[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&adj[i][j]);	
}
int checkPath(int adj[MAX][MAX],int n,int visited[MAX],int src,int dest)
{
	int q[n];					//Create Queue
	int front=0,rear=-1;		//Init Queue
	
	q[++rear]=src;		//Enqueue src
	visited[src]=1;		//Mark src visited
	
	int v;
	while(front <= rear)	//q is not empty
	{
		v=q[front++];		//deque
//		printf("%d ",v);
		
		for(int i=0;i<n;i++)
		{
			if(adj[v][i] && visited[i]==0)	//Find vertices adj to v & which are unvisited
			{
				if(i==dest)
					return 1;
				q[++rear]=i;		//Enq adj vertex
				visited[i]=1;		//Mark adj vertex as visited
			}
		}
	}
	return 0;
}