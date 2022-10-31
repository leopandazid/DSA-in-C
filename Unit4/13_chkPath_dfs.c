//Check if there exists a path from src to dest using DFS

#include<stdio.h>
#define MAX 10

void createGraph(int adj[MAX][MAX],int n);
int checkPath(int adj[MAX][MAX],int n,int visited[MAX],int src,int dest);
int main()
{
	int n;
	int adj[MAX][MAX]={0};
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
int checkPath(int adj[MAX][MAX],int n,int visited[MAX],int src,int dest)
{
	visited[src]=1;
//	printf("%d ",src);
	
	for(int i=0;i<n;i++)
	{
		if(adj[src][i] && visited[i]==0)
		{
			if(i==dest)
				return 1;
			return checkPath(adj,n,visited,i,dest);
		}
	}
	return 0;
}