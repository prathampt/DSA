typedef struct node
{
    int MIS;
    char *name;
    struct node *left;
    struct node *right;
} Node;

typedef Node *Tree;

void initBST(Tree *t);
Node *generateNode(int MIS, char *name);
void insertNode(Tree *t, int MIS, char *name); // Using recursion...

int count(Tree t);

void removeNode(Tree *t, int MIS);
int search(Tree t, int MIS); // Using recursion...

void preorderTraversal(Tree t);
void inorderTraversal(Tree t);
void postorderTraversal(Tree t);
