#include <stdio.h>

typedef struct graph
{
    int ** G;
    int vertices;
    int edges;
} Graph;

void init(Graph *g, int vertices);
void addEdge(Graph *g, int src, int des, int weight);
void createGraph(Graph *g, FILE *f);
void display(Graph g);
int isAdjacent(Graph g, int src, int des);
int getDegree(Graph g, int vertex);
int isConnected(Graph g);
void displayComponents(Graph g);
