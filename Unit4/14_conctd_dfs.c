//To check if an undirected graph is connected or not using DFS
#include<stdio.h>
#define MAX 10

void createGraph(int adj[MAX][MAX],int n);
void dfs(int adj[MAX][MAX],int n,int visited[MAX],int src);
int connected(int adj[MAX][MAX],int n);
int main()
{
	int n;
	int adj[MAX][MAX]={0};

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
	int src,dest;
	printf("Enter -1 -1 to stop adding edges\n");
	while(1)
	{
		scanf("%d%d",&src,&dest);
		if(src<0 || dest<0 || src>=n || dest>=n )
			break;
		adj[src][dest]=1;
	}
}
void dfs(int adj[MAX][MAX],int n,int visited[MAX],int src)
{
	visited[src]=1;
	printf("%d ",src);
	
	for(int i=0;i<n;i++)
		if(adj[src][i] && visited[i]==0)
			dfs(adj,n,visited,i);
}
int connected(int adj[MAX][MAX],int n)
{
	int visited[MAX]={0};
	
	dfs(adj,n,visited,0);
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
			return 0;
	}
	return 1;
}