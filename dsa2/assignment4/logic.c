#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void init(AVLtree * t){
    *t = NULL;
    return;
}

Node * generateNode(char * name){
    Node * nn = (Node *)malloc(sizeof(Node));
    if (!nn) return;

    nn->balancingFactor = 0;
    nn->left = NULL;
    nn->right = NULL;
    nn->parent = NULL;
    nn->name = (char *)malloc(strlen(name)+1);
    strcpy(nn->name, name);
    
    return nn;
}

void insertNode(AVLtree * t, char * name);
int height(AVLtree t);
void removeNode(AVLtree * t, char * name);
void traverse(AVLtree t); // Display name, parent and the balancing factor of each node...
void destroyTree(AVLtree * t);