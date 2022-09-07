#include <stdio.h>
#include <stdlib.h>

struct node {
	int vertex;
	struct node* next;
};

struct node* createNode(int);

struct Graph {
	int vertex;
	struct node** adjList;
};
// create a Node
struct node* createNode(int v) {
	struct node* newNode = malloc(sizeof(struct node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

// create a graph

struct Graph* createGraph(int vertices) {
	struct Graph * graph = malloc(sizeof(struct Graph));
	graph->vertex = vertices;
	graph->adjList = malloc(vertices* sizeof(struct node*));

	int i;
	for (i =0; i < vertices; i++)
		graph->adjList[i] = NULL;

	return graph;
}
	

// Add edge

void addEdge(struct Graph* graph, int s, int d) {
	//add edge from s to d
	struct node* newNode = createNode(d);
	newNode->next = graph->adjList[s];
	graph->adjList[s] = newNode;

	// add edge from d to s
	newNode = createNode(s);
	newNode->next = graph->adjList[d];
	graph->adjList[d] = newNode;

}

void printGraph(struct Graph* graph) {
	int v;
	for(v = 0; v < graph->vertex; v++){
		struct node* temp = graph->adjList[v];
		printf("\n  Vertex %d \n",v);

		while(temp) {
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}

		printf("\n");
	}
}

int main() {
	struct Graph* graph = createGraph(4);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 0, 3);
	addEdge(graph, 1, 2);

	printGraph(graph);
	return 0;
}


