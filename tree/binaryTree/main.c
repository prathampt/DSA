#include "infixToExpressionTree.c"

int main(){
    Tree tree;
    init(&tree);

    char * userData = "-874 * ( (6 + -98) * (3 + 20) )";

    expressionTree(&tree, userData);

    inorderTraversal(tree);
    printf("\n");

    return 0;
}