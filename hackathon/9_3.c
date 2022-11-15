//DFS traversal for a connected graph
//Adjacency matrix representation

#include<stdio.h>
#define MAX 10

void createGraph(int adj[MAX][MAX],int n);
void dfs(int adj[MAX][MAX],int n,int visited[MAX],int src);
int main()
{
	int n,src;
	
	int adj[MAX][MAX]={0};
	int visited[MAX]={0};
	
	printf("Enter the no. of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency information\n");
	createGraph(adj,n);
	
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	
	printf("DFS traversal\n");
	dfs(adj,n,visited,src);
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