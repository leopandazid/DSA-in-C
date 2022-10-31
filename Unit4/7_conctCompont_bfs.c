//To find the number of connected components
//in an undirected graph using BFS
//adjacency matric representation
#include<stdio.h>
#define MAX 10

void createGraph(int adj[MAX][MAX]);
void bfs(int adj[MAX][MAX],int n,int visited[MAX],int src);
int connectedComponent(int adj[MAX][MAX],int n);

int main()
{
	int n;
	int adj[MAX][MAX]={0};

	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter adjacency info\n");
	createGraph(adj);
	
	int res=connectedComponent(adj,n);
		printf("No. of connected components %d\n",res);
}
void createGraph(int adj[MAX][MAX])
{
	int src,dest;
	printf("Enter -1 -1 to stop adding edges\n");
	while(1)
	{
		scanf("%d%d",&src,&dest);
		if(src == -1 || dest == -1)
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

int connectedComponent(int adj[MAX][MAX],int n)
{
	int visited[MAX]={0};
	
	int count=1;
	bfs(adj,n,visited,0);
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			count++;
			bfs(adj,n,visited,i);
		}
	}
	return count;
}