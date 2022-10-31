//Given a dircted graph check if it is 
//strongly connected or weakly connectedor disconnected
//using Breadth First Search (BFS) Traversal
//adjacency matrix representation

#include<stdio.h>
#define MAX 10

void createGraph(int adj[MAX][MAX],int n);
int stronglyConnected(int adj[MAX][MAX],int n);
void removeEdgeDirection(int a[MAX][MAX],int b[MAX][MAX],int n);
int weaklyConnected(int adj[MAX][MAX],int n);

int main()
{
	int n;
	int adj[MAX][MAX]={0};
	int b[MAX][MAX]={0};

	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter adjacency info\n");
	createGraph(adj,n);
	
	if(stronglyConnected(adj,n))
		printf("Graph is strongly connected\n");
	else
	{
		removeEdgeDirection(adj,b,n);
		if(weaklyConnected(b,n))
			printf("Graph is weakly connected\n");
		else
			printf("Graph is disconnected\n");
	}
		
}

void createGraph(int adj[MAX][MAX],int n)
{
	printf("Enter -1 -1 to stop adding edges\n");
	int src,dest;
	while(1)
	{
		scanf("%d%d",&src,&dest);
		if(src<0 || dest<0 || src>=n || dest >=n)
			break;
		adj[src][dest]=1;
	}
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

int stronglyConnected(int adj[MAX][MAX],int n)
{
	int visited[MAX]={0};
	
	for(int v=0;v<n;v++)
	{
		bfs(adj,n,visited,v);
		for(int i=0;i<n;i++)
			if(visited[i]==0)
				return 0;
		for(int j=0;j<n;j++)
			visited[j]=0;
	}
	return 1;
}
void removeEdgeDirection(int a[MAX][MAX],int b[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i][j]==1)
				b[i][j]=b[j][i]=1;
}
int weaklyConnected(int adj[MAX][MAX],int n)
{
	int visited[MAX]={0};
	
	bfs(adj,n,visited,0);
	
	for(int i=0;i<n;i++)
		if(visited[i]==0)
			return 0;
		
	return 1;
}