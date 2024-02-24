typedef struct node
{
    int balancingFactor;
    char *name;
    struct node *left;
    struct node *right;
    struct node *parent;
} Node;

typedef Node *AVLtree;

void init(AVLtree *t);
Node *generateNode(char *name);
void insertNode(AVLtree *t, char *name);
void balanceFactor(Node *node);
void removeNode(AVLtree *t, char *name);
void traverse(AVLtree t); // Display name, parent and the balancing factor of each node...
void destroyTree(AVLtree *t);
int height(AVLtree t); // This is just a comment I am writing form vim...

void RL(AVLtree *t, Node * n);
void LR(AVLtree *t, Node * n);
void LL(AVLtree *t, Node * n);
void RR(AVLtree *t, Node * n);
void adjustImbalance(AVLtree *t, Node *n);
