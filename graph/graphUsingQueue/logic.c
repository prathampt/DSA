#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "header.h"
#include "queue.c"

void initGraph(Graph *g, int numberOfVertices)
{
    g->V = numberOfVertices;

    g->array = (Vertex *)malloc(sizeof(Vertex) * numberOfVertices);

    for (int i = 0; i < numberOfVertices; i++)
    {
        g->array[i].vertex = CHAR_MIN;
    }

    return;
}

Node *generateNode(char vertex, int weight)
{
    Node *nn = (Node *)malloc(sizeof(Node));

    if (!nn)
        return NULL;

    nn->vertex = vertex;
    nn->weight = weight;
    nn->next = NULL;

    return nn;
}

void addVertex(Graph *g, char vertex)
{

    if (checkVertex(*g, vertex) != -1)
        return;

    for (int i = 0; i < g->V; i++)
    {
        if (g->array[i].vertex == CHAR_MIN)
        {
            g->array[i].vertex = vertex;
            return;
        }
    }

    printf("Can add only %d nodes as mentioned earlier in Graph init function!\n", g->V);

    return;
}

int checkVertex(Graph g, char vertex)
{

    for (int i = 0; i < g.V; i++)
    {
        if (g.array[i].vertex == vertex)
        {
            return i;
        }
    }

    return -1;
}

void addEdge(Graph *g, char vertex1, char vertex2, int weight)
{
    if (checkVertex(*g, vertex1) == -1)
        addVertex(g, vertex1);
    if (checkVertex(*g, vertex2) == -1)
        addVertex(g, vertex2);

    for (int i = 0; i < g->V; i++)
    {
        if (g->array[i].vertex == vertex1)
        {
            Node *t = g->array[i].edges;
            g->array[i].edges = generateNode(vertex2, weight);
            g->array[i].edges->next = t;
            break;
        }
    }

    for (int i = 0; i < g->V; i++)
    {
        if (g->array[i].vertex == vertex2)
        {
            Node *t = g->array[i].edges;
            g->array[i].edges = generateNode(vertex1, weight);
            g->array[i].edges->next = t;
            break;
        }
    }

    return;
}

void createGraph(Graph *g, FILE *f)
{
    int vertices, w;
    char c = 'A';
    fscanf(f, "%d", &vertices);

    initGraph(g, vertices);

    for (int i = 0; i < vertices; i++)
    {
        addVertex(g, c);
        for (int j = 0; j < vertices; j++)
        {
            fscanf(f, "%d", &w);
            if (w && i <= j)
                addEdge(g, c, 'A' + j, w);
        }
        c++;
    }

    return;
}

void displayGraph(Graph g)
{

    for (int i = 0; i < g.V; i++)
    {
        printf("%c: ", g.array[i].vertex);

        Node *t = g.array[i].edges;

        while (t)
        {
            printf("%c[%d] ", t->vertex, t->weight);
            t = t->next;
        }

        printf("\n");
    }

    return;
}

void dfs(Graph g, char *visited, char vertex)
{
    visited[vertex - 'A'] = 1;

    Node *e = g.array[checkVertex(g, vertex)].edges;

    while (e)
    {
        if (!visited[e->vertex - 'A'])
        {
            printf("%c ", e->vertex);
            dfs(g, visited, e->vertex);
        }
        e = e->next;
    }

    return;
}

void bfs(Graph g, char * visited, char vertex){
    Queue q;
    initQ(&q);

    enQueue(&q, vertex);

    visited[vertex - 'A'] = 1;

    while (!isEmpty(q))
    {
        Node *e = g.array[checkVertex(g, vertex)].edges;

        while (e)
        {
            if (!visited[e->vertex - 'A']){
                enQueue(&q, e->vertex);
                visited[e->vertex - 'A'] = 1;
            }
            e = e->next;
        }
        printf("%c ", deQueue(&q));
        if (q.front) vertex = q.front->data;
    }

    return;
}

void primMST(Graph g) {
    int V = g.V;
    char* parent = (char*)malloc(V * sizeof(char)); 
    int* key = (int*)malloc(V * sizeof(int)); 
    bool* mstSet = (bool*)malloc(V * sizeof(bool));

    if (!parent || !key || !mstSet) {
        return;
    }

    for (int i = 0; i < V; ++i) {
        parent[i] = ' ';
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;

    for (int count = 0; count < V; ++count) {
        int minKey = INT_MAX;
        int minIndex;
        for (int v = 0; v < V; ++v) {
            if (mstSet[v] == false && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        mstSet[minIndex] = true;

        Node* temp = g.array[minIndex].edges;
        while (temp != NULL) {
            int v = checkVertex(g, temp->vertex);
            if (temp->weight && mstSet[v] == false && temp->weight < key[v]) {
                parent[v] = g.array[minIndex].vertex;
                key[v] = temp->weight;
            }
            temp = temp->next;
        }
    }

    printf("Minimum Spanning Tree using Prim's algorithm:\n");
    for (int i = 1; i < V; ++i)
        printf("(%c - %c) Weight: %d\n", parent[i], g.array[i].vertex, key[i]);

    free(parent);
    free(key);
    free(mstSet);
}
