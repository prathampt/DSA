typedef struct node {
    int balancingFactor;
    char * name;
    struct node * left;
    struct node * right;
    struct node * parent;
} Node;

typedef Node * AVLtree;

void init(AVLtree * t);
Node * generateNode(char * name);
void insertNode(AVLtree * t, char * name);
int height(AVLtree t);
void removeNode(AVLtree * t, char * name);
void traverse(AVLtree t); // Display name, parent and the balancing factor of each node...
void destroyTree(AVLtree * t);