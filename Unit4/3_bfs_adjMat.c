//Breadth First Search (BFS) Traversal using adjacency matrix
//For a connected graph
#include<stdio.h>
#define MAX 10

void createGraph(int adj[MAX][MAX],int n);
void bfs(int adj[MAX][MAX],int n,int visited[MAX],int src);
int main()
{
	int n;
	int adj[MAX][MAX];
	int visited[MAX]={0};
	int src;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter adjacency info\n");
	createGraph(adj,n);
	
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	
	printf("BFS Traversal\n");
	bfs(adj,n,visited,src);
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
		printf("%d ",v);
		
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