//BFS -- Adjacencey List

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef struct Graph {
	int V;
	bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;
Graph* Graph_create(int V)
{
	Graph* g = malloc(sizeof(Graph));
	g->V = V;

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			g->adj[i][j] = false;
		}
	}
	return g;
}
void Graph_destroy(Graph* g){
	free(g); 
	}
void Graph_addEdge(Graph* g, int v, int w)
{
	g->adj[v][w] = true;
}
void Graph_BFS(Graph* g, int s)
{
	bool visited[MAX_VERTICES];
	for (int i = 0; i < g->V; i++) {
		visited[i] = false;
	}

	// Create a queue for BFS
	int queue[MAX_VERTICES];
	int front = 0, rear = 0;
	visited[s] = true;
	queue[rear++] = s;

	while (front != rear) {
		s = queue[front++];
		printf("%d ", s);
		for (int adjacent = 0; adjacent < g->V;	adjacent++) {
			if (g->adj[s][adjacent] && !visited[adjacent]) {
				visited[adjacent] = true;
				queue[rear++] = adjacent;
			}
		}
	}
}

int main()
{
	Graph* g = Graph_create(4);
	Graph_addEdge(g, 0, 1);
	Graph_addEdge(g, 0, 2);
	Graph_addEdge(g, 1, 2);
	Graph_addEdge(g, 2, 0);
	Graph_addEdge(g, 2, 3);
	Graph_addEdge(g, 3, 3);

	printf("Following is BFS starting from vertex 2 \n");
	Graph_BFS(g, 2);
	Graph_destroy(g);
	return 0;
}
________________________________________________________________________________________________________________-

// adjacency matrix

// C code to implement above approach
#include <stdio.h>
#include <stdlib.h>

// Globally declared visited array
int vis[100];

// Graph structure to store number of vertices and edges and Adjacency matrix
struct Graph {
	int V;
	int E;
	int** Adj;
};

// Function to input data of graph
struct Graph* adjMatrix()
{
	struct Graph* G = (struct Graph*)
		malloc(sizeof(struct Graph));
	if (!G) {
		printf("Memory Error\n");
		return NULL;
	}
	G->V = 7;
	G->E = 7;

	G->Adj = (int**)malloc((G->V) * sizeof(int*));
	for (int k = 0; k < G->V; k++) {
		G->Adj[k] = (int*)malloc((G->V) * sizeof(int));
	}

	for (int u = 0; u < G->V; u++) {
		for (int v = 0; v < G->V; v++) {
			G->Adj[u][v] = 0;
		}
	}
	G->Adj[0][1] = G->Adj[1][0] = 1;
	G->Adj[0][2] = G->Adj[2][0] = 1;
	G->Adj[1][3] = G->Adj[3][1] = 1;
	G->Adj[1][4] = G->Adj[4][1] = 1;
	G->Adj[1][5] = G->Adj[5][1] = 1;
	G->Adj[1][6] = G->Adj[6][1] = 1;
	G->Adj[6][2] = G->Adj[2][6] = 1;

	return G;
}

// DFS function to print DFS traversal of graph
void DFS(struct Graph* G, int u)
{
	vis[u] = 1;
	printf("%d ", u);
	for (int v = 0; v < G->V; v++) {
		if (!vis[v] && G->Adj[u][v]) {
			DFS(G, v);
		}
	}
}

// Function for DFS traversal
void DFStraversal(struct Graph* G)
{
	for (int i = 0; i < 100; i++) {
		vis[i] = 0;
	}
	for (int i = 0; i < G->V; i++) {
		if (!vis[i]) {
			DFS(G, i);
		}
	}
}

// Driver code
void main()
{
	struct Graph* G;
	G = adjMatrix();
	DFStraversal(G);
}

