typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

typedef Node *Tree;

void init(Tree *t);
Node *generateNode(int data);

/*
Traversal Algorithms...
*/

void preorderTraversal(Tree t);
void inorderTraversal(Tree t);
void postorderTraversal(Tree t);

int count(Tree t); // This counts the number of nodes in the tree...

void insert(Tree *t, int data);
int search(Tree t, int data);
void delete(Tree *t, int data);
