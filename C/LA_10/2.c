/*
    Write a program to implement breadth first search algorithm.
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

// Function to perform Breadth-First Search on the graph
void BFS(struct Graph *graph, int startVertex)
{
    // Array to keep track of visited vertices
    bool visited[MAX_VERTICES] = {false};

    // Queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Mark the starting vertex as visited and enqueue it
    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("Breadth-First Search starting from vertex %d: ", startVertex);

    while (front < rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Explore adjacent vertices
        struct Node *temp = graph->adjacencyList[currentVertex];
        while (temp != NULL)
        {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }

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

    // Perform BFS starting from vertex 0
    BFS(graph, 0);

    // Free allocated memory
    free(graph);

    return 0;
}
