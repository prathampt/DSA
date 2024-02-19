typedef struct node
{
    char * s;
    struct node * left;
    struct node * right;
} Node;

typedef Node * Tree;

void init(Tree *t);
Node *generateNode(char * string);
void inorderTraversal(Tree t);