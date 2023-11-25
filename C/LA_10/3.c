/*
    Write a program to implement depth first search algorithm.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of vertices
#define MAX_VERTICES 100

// Structure to represent a node in the adjacency list
struct Node
{
    int vertex;
    struct Node *next;
};

// Structure to represent the adjacency list
struct Graph
{
    struct Node *adjacencyList[MAX_VERTICES];
    int vertices;
};

// Function to create a new node
struct Node *createNode(int vertex)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // For undirected graph, add an edge in the opposite direction as well
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// Function to perform Depth-First Search on the graph (recursive implementation)
void DFSRecursive(struct Graph *graph, int vertex, bool visited[])
{
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node *temp = graph->adjacencyList[vertex];
    while (temp != NULL)
    {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex])
        {
            DFSRecursive(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to initiate DFS traversal
void DFS(struct Graph *graph, int startVertex)
{
    bool visited[MAX_VERTICES] = {false};
    printf("Depth-First Search starting from vertex %d: ", startVertex);
    DFSRecursive(graph, startVertex, visited);
    printf("\n");
}

// Driver program
int main()
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = 6;

    // Initialize the adjacency list
    for (int i = 0; i < MAX_VERTICES; ++i)
    {
        graph->adjacencyList[i] = NULL;
    }

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    // Perform DFS starting from vertex 0
    DFS(graph, 0);

    // Free allocated memory
    free(graph);

    return 0;
}
