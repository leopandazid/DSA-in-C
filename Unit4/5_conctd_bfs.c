//To check if an undirected graph is connected or not using BFS
#include<stdio.h>
#define MAX 10

void createGraph(int adj[MAX][MAX],int n);
void bfs(int adj[MAX][MAX],int n,int visited[MAX],int src);
int connected(int adj[MAX][MAX],int n);
int main()
{
	int n;
	int adj[MAX][MAX];

	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter adjacency info\n");
	createGraph(adj,n);
	
	if(connected(adj,n))
		printf("Graph is connected\n");
	else 
		printf("Graph is disconnected\n");
	
}
void createGraph(int adj[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&adj[i][j]);	
}
void bfs(int adj[MAX][MAX],int n,int visited[MAX],int src)
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
				q[++rear]=i;		//Enq adj vertex
				visited[i]=1;		//Mark adj vertex as visited
			}
		}
	}
}

int connected(int adj[MAX][MAX],int n)
{
	int visited[MAX]={0};
	
	bfs(adj,n,visited,0);
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
			return 0;
	}
	return 1;
}