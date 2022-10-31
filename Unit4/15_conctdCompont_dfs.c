//To find the number of connected components
//in an undirected graph using BFS
//adjacency matric representation
#include<stdio.h>
#define MAX 10

void createGraph(int adj[MAX][MAX]);
void dfs(int adj[MAX][MAX],int n,int visited[MAX],int src);
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
void dfs(int adj[MAX][MAX],int n,int visited[MAX],int src)
{
	visited[src]=1;
//	printf("%d ",src);
	
	for(int i=0;i<n;i++)
		if(adj[src][i] && visited[i]==0)
			dfs(adj,n,visited,i);
}
int connectedComponent(int adj[MAX][MAX],int n)
{
	int visited[MAX]={0};
	
	int count=1;
	dfs(adj,n,visited,0);
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			count++;
			dfs(adj,n,visited,i);
		}
	}
	return count;
}