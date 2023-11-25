/*
    Write a program to represent a graph using adjacency matrix/list and perform basic operations like degree (in/out) of a vertex, adjacent vertices, number of edges, etc.
*/

#include <stdio.h>
#include <stdlib.h>

// Maximum number of vertices in the graph
#define MAX_VERTICES 100

// Structure to represent a graph
struct Graph
{
    int vertices;
    int edges;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to initialize a graph with given number of vertices
void initializeGraph(struct Graph *graph, int vertices)
{
    graph->vertices = vertices;
    graph->edges = 0;

    // Initialize the adjacency matrix with zeros
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int source, int destination)
{
    if (source >= 0 && source < graph->vertices && destination >= 0 && destination < graph->vertices)
    {
        graph->adjacencyMatrix[source][destination] = 1;
        graph->edges++;
    }
    else
    {
        printf("Invalid vertices for edge.\n");
    }
}

// Function to calculate the in-degree of a vertex
int inDegree(struct Graph *graph, int vertex)
{
    int inDegree = 0;
    for (int i = 0; i < graph->vertices; i++)
    {
        if (graph->adjacencyMatrix[i][vertex] == 1)
        {
            inDegree++;
        }
    }
    return inDegree;
}

// Function to calculate the out-degree of a vertex
int outDegree(struct Graph *graph, int vertex)
{
    int outDegree = 0;
    for (int i = 0; i < graph->vertices; i++)
    {
        if (graph->adjacencyMatrix[vertex][i] == 1)
        {
            outDegree++;
        }
    }
    return outDegree;
}

// Function to check if there is an edge between two vertices
int isAdjacent(struct Graph *graph, int source, int destination)
{
    if (source >= 0 && source < graph->vertices && destination >= 0 && destination < graph->vertices)
    {
        return graph->adjacencyMatrix[source][destination] == 1;
    }
    else
    {
        printf("Invalid vertices.\n");
        return 0;
    }
}

// Function to print the adjacency matrix of the graph
void printGraph(struct Graph *graph)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++)
    {
        for (int j = 0; j < graph->vertices; j++)
        {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main()
{
    struct Graph graph;
    int vertices, edges, source, destination;

    // Input the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initializeGraph(&graph, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Input the edges
    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &source, &destination);
        addEdge(&graph, source, destination);
    }

    // Perform basic operations
    printf("Number of vertices: %d\n", graph.vertices);
    printf("Number of edges: %d\n", graph.edges);

    // Display adjacency matrix
    printGraph(&graph);

    // Perform additional operations (e.g., in-degree, out-degree, adjacency check)
    printf("Enter a vertex to find its in-degree: ");
    scanf("%d", &source);
    printf("In-degree of vertex %d: %d\n", source, inDegree(&graph, source));

    printf("Enter a vertex to find its out-degree: ");
    scanf("%d", &source);
    printf("Out-degree of vertex %d: %d\n", source, outDegree(&graph, source));

    printf("Enter two vertices to check if there is an edge between them (source destination): ");
    scanf("%d %d", &source, &destination);
    if (isAdjacent(&graph, source, destination))
    {
        printf("There is an edge between %d and %d.\n", source, destination);
    }
    else
    {
        printf("There is no edge between %d and %d.\n", source, destination);
    }

    return 0;
}
