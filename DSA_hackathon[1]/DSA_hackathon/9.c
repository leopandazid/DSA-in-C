// 9) Perform BFS and DFS traversal for a connected/disconnected, directed/undirected graph
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
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			printf("\n");
			bfs(adj,n,visited,i);
		}
	}
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

//////////////////////////////
////////////////////////////////////
//////////////////////////////////////
//adjacency list
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct node
{
	int info;
	struct node *next;
}NODE;
void createGraph(NODE *V[MAX],int n);
void bfs(NODE *V[MAX],int n,int visited[MAX],int src);
int main()
{
	int n;
	NODE *V[MAX]={NULL};
	int visited[MAX]={0};
	int src;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter adjacency info\n");
	createGraph(V,n);
	
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	
	printf("BFS Traversal\n");
	bfs(V,n,visited,src);
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			printf("\n");
			bfs(V,n,visited,i);
		}
	}
}
void addEdge(NODE *V[MAX],int src,int dest)
{
	NODE *newNode=malloc(sizeof(newNode));
	
	newNode->info=dest;
	newNode->next=V[src];
	V[src]=newNode;
}
void createGraph(NODE *V[MAX],int n)
{
	printf("Enter -1 -1 to stop adding edges\n");
	int src,dest;
	while(1)
	{
		scanf("%d%d",&src,&dest);
		if(src<0 || dest<0 || src>=n || dest >=n)
			break;
		addEdge(V,src,dest);
	}
}
void bfs(NODE *V[MAX],int n,int visited[MAX],int src)
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
		
		NODE *p=V[v];
		while(p!=NULL)
		{	//To find adj vertex which is unvisited
			if(visited[p->info]==0)	
			{
				q[++rear]=p->info;	//Enq unvisited vertex
				visited[p->info]=1;	//Mark the adj unvisited vertex as visited
			}
			p=p->next;
		}
	}
}
/////////////////////////////
/////////////////////////////
////////////////////////////
//dfs adjacency matrix recurssion
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
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////
//DFS traversal for a connected graph
//Adjacency List representation

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct node
{
	int info;
	struct node *next;
}NODE;
void createGraph(NODE *V[MAX],int n);
void dfs(NODE *V[MAX],int n,int visited[MAX],int src);
int main()
{
	int n,src;
	
	NODE *V[MAX]={NULL};
	int visited[MAX]={0};
	
	printf("Enter the no. of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency information\n");
	createGraph(V,n);
	
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	
	printf("DFS traversal\n");
	dfs(V,n,visited,src);
}
void addEdge(NODE *V[MAX],int src,int dest)
{
	NODE *newNode=malloc(sizeof(newNode));
	
	newNode->info=dest;
	newNode->next=V[src];
	V[src]=newNode;
}
void createGraph(NODE *V[MAX],int n)
{
	printf("Enter -1 -1 to stop adding edges\n");
	int src,dest;
	while(1)
	{
		scanf("%d%d",&src,&dest);
		if(src<0 || dest<0 || src>=n || dest >=n)
			break;
		addEdge(V,src,dest);
	}
}

void dfs(NODE *V[MAX],int n,int visited[MAX],int src)
{
	visited[src]=1;
	printf("%d ",src);
	
	NODE *p=V[src];
	while(p!=NULL)
	{
		if(visited[p->info]==0)
			dfs(V,n,visited,p->info);
		p=p->next;
	}
}

//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////
/DFS traversal for a connected graph
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
	int s[MAX];		//create stack
	int top=-1;		//initialize stack

	s[++top]=src;
	visited[src]=1;
	printf("%d ",src);
	
	int v;
	while(top!=-1)
	{
		v=s[top];		//Peek the stack
		int i;
		for(i=0;i<n;i++)
		{
			if(adj[v][i] && !visited[i]) //if an adj & unvisited vertex is found, start exploring that vertex
				break;
		}
		
		if(i<n)
		{
			s[++top]=i;
			visited[i]=1;
			printf("%d ",i);
		}
		else
			top--;
	}
}