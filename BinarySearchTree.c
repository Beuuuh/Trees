#include "stdio.h"
#include "stdlib.h"
#include "./BinarySearchTree.h"

BST* createEmptyTree() {
    BST* tree = (BST*) malloc(sizeof(BST));
    return tree;
}

int isEmpty(BST* tree) {
    return (tree == NULL);
}

BST* insertElement(BST* tree, int value) {
    if(isEmpty(tree)) {
        BST* node = createEmptyTree();
        node->value = value;
        return node;
    }

    if(value <= tree->value) {
        tree->left = insertElement(tree, value);
    }
    
    tree->right = insertElement(tree, value);
    return tree;
}

