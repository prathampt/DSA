#include <stdlib.h>
#include "header.h"

void init(Graph *g, int vertices)
{
    g->vertices = vertices;
    g->edges = 0;
    g->G = (int **)malloc(vertices * sizeof(int *));

    for (int i = 0; i < vertices; i++)
    {
        g->G[i] = (int *)calloc(vertices, sizeof(int));
    }

    return;
}

void addEdge(Graph *g, int src, int des, int weight)
{
    g->G[src][des] = weight;
    g->G[des][src] = weight;
    g->edges++;
    return;
}

void createGraph(Graph *g, FILE *f)
{
    int vertices, t;
    fscanf(f, "%d", &vertices);

    init(g, vertices);

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            fscanf(f, "%d", &t);
            if (t && i <= j)
                addEdge(g, i, j, t);
        }
    }

    return;
}

void display(Graph g)
{
    int vertices = g.vertices;

    printf("The graph as a adjacency matrix:\n");

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", g.G[i][j]);
        }

        printf("\n");
    }

    return;
}

int isAdjacent(Graph g, int src, int des){
    if (g.G[src][des] != 0) return 1;
    
    return 0;
}

int getDegree(Graph g, int vertex){
    int degree = 0;

    for (int i = 0; i < g.vertices; i++)
    {
        if (g.G[vertex][i] != 0) degree++;
    }

    return degree;    
}

int isConnected(Graph g){ // Not correct function...
    int vertices = g.vertices;

    int i = 0, j = 0;

    while (i < vertices){ // Have to do proper DFS here, as this only tells us whether only one component is isolated...
        j = 0;
        while (j < vertices)
        {
            if (g.G[i][j] != 0){
                i++;
                break;
            }
            else 
                j++;
        }

        if (j == vertices) return 0;
        
    }

    return 1;
}

void displayComponents(Graph g){
    int vertices = g.vertices;

    for (int i = 0; i < vertices; i++)
    {
        printf("%d: ", i);
        for (int j = 0; j < vertices; j++)
        {
            if (g.G[i][j] != 0) printf("%d ", j);
        }

        printf("\n");
        
    }

    return;
    
}