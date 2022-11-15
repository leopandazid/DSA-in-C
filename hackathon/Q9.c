//Perform BFS and DFS traversal for a connected/disconnected, directed/undirected graph

//Pgm1
//Determine if the undirected graph is connected or not using BFS
//Adjacency Matrix representation
#define MAX 10
#include <stdio.h>

void readGraph(int a[MAX][MAX], int n);
void bfs(int a[MAX][MAX], int n, int visited[MAX], int source);
int connected(int a[MAX][MAX], int n);
int main()
{
	int a[MAX][MAX], n;

	printf("Enter the no. of vertices\n");
	scanf("%d", &n);

	printf("Enter the values to adj matrix\n");
	readGraph(a, n);

	if (connected(a, n))
		printf("Graph is connected\n");
	else
		printf("Graph is disconnected\n");
}

void readGraph(int a[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
}
void bfs(int a[MAX][MAX], int n, int visited[MAX], int source)
{
	int q[n]; //Queue
	int f = 0, r = -1;

	q[++r] = source;
	visited[source] = 1;

	int v;
	while (f <= r) //until q is not empty
	{
		v = q[f++];
		//		printf("%d ",v);

		for (int i = 0; i < n; i++)
		{
			if (a[v][i] && visited[i] == 0)
			{
				q[++r] = i;
				visited[i] = 1;
			}
		}
	}
}
int connected(int a[MAX][MAX], int n)
{
	int visited[MAX] = {0}, source = 0;
	bfs(a, n, visited, source);
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			return 0;
		}
	}
	return 1;
}

//Pgm2
//Determine if the undirected graph is connected or not using DFS
//Adjacency Matrix representation
#define MAX 10
#include <stdio.h>

void readGraph(int a[MAX][MAX], int n);
void dfs(int a[MAX][MAX], int n, int visited[MAX], int source);
int connected(int a[MAX][MAX], int n);

int main()
{
	int a[MAX][MAX], n;

	printf("Enter the no. of vertices\n");
	scanf("%d", &n);

	printf("Enter the values to adj matrix\n");
	readGraph(a, n);

	if (connected(a, n))
		printf("Graph is connected\n");
	else
		printf("Graph is disconnected\n");
}

void readGraph(int a[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
}

void dfs(int a[MAX][MAX], int n, int visited[MAX], int source)
{
	visited[source] = 1;
	//	printf("%d ",source);	//To print path

	for (int i = 0; i < n; i++)
	{
		if (a[source][i] && visited[i] == 0)
			dfs(a, n, visited, i);
	}
}

int connected(int a[MAX][MAX], int n)
{
	int visited[MAX] = {0}, source = 0;
	dfs(a, n, visited, source);
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			return 0;
		}
	}
	return 1;
}
