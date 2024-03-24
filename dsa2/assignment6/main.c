#include "logic.c"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Please pass the text file name containing the graph matrix as an argument.\n");
        return 1;
    }
    else if (argc != 2)
    {
        printf("Please pass on one argument!\n");
        return 1;
    }

    Graph g;

    FILE *f = fopen(argv[1], "r");

    createGraph(&g, f);

    printf("Displaying the graph:\n");
    display(g);

    int vertices = g.vertices;

    printf("Degree of each vertex is: \n");

    for (int i = 0; i < vertices; i++)
    {
        printf("%d: %d\n", i, getDegree(g, i));
    }

    printf("Is the given graph connected? %s\n", isConnected(g) ? "Yes!" : "No!");

    printf("Displaying the components of the graph: \n");

    displayComponents(g);

    printf("Checking adjacency:\n");

    int src = 1, des = 3;
    printf("Is %d and %d adjacent? %s\n", src, des, isAdjacent(g, src, des) ? "Yes!" : "No!");

    src = 0;
    des = 2;
    printf("Is %d and %d adjacent? %s\n", src, des, isAdjacent(g, src, des) ? "Yes!" : "No!");

    return 0;
}