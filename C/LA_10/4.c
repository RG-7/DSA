/*
    Write a program to implement kruskal's minimum spanning tree algorithm.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge
{
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset
{
    int parent;
    int rank;
};

// Function to find the parent of a node in a subset
int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets
void unionSets(struct Subset subsets[], int x, int y)
{
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else
    {
        subsets[rootX].parent = rootY;
        subsets[rootY].rank++;
    }
}

// Function to compare two edges based on their weights
int compareEdges(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Function to perform Kruskal's algorithm and print the minimum spanning tree
void kruskal(struct Edge edges[], int V, int E)
{
    // Sort the edges in non-decreasing order of their weights
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    // Allocate memory for the subsets
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));

    // Initialize each subset with its parent and rank
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Initialize the result array to store the minimum spanning tree
    struct Edge *result = (struct Edge *)malloc((V - 1) * sizeof(struct Edge));

    int e = 0; // Index variable for result[]
    int i = 0; // Index variable for sorted edges

    // Build the minimum spanning tree
    while (e < V - 1 && i < E)
    {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // Include the edge in the result if it does not form a cycle
        if (x != y)
        {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    // Print the minimum spanning tree
    printf("Edges in the minimum spanning tree:\n");
    for (int i = 0; i < e; i++)
        printf("%d -- %d\t(weight %d)\n", result[i].src, result[i].dest, result[i].weight);

    free(subsets);
    free(result);
}

// Driver program
int main()
{
    // Example graph represented by the edges
    // (src, dest, weight)
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    kruskal(edges, V, E);

    return 0;
}