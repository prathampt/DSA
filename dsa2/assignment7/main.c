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
    displayGraph(g);

    printf("DFS:\n");
    char *visited = (char *)calloc(g.V, sizeof(char));

    printf("C ");
    dfs(g, visited, 'C');
    printf("\n");

    printf("BFS:\n");
    char *visited1 = (char *)calloc(g.V, sizeof(char));

    bfs(g, visited1, 'C');
    printf("\n");

    primMST(g);

    return 0;
}