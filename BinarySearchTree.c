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

BST* removeElement(BST* tree, int value) {
    if(isEmpty(tree)) {
        return tree;
    }

    if(value < tree->value) {
        tree->left = removeElement(tree->left, value);
    } else if(value > tree->value) {
        tree->right = removeElement(tree->right, value);
    } else {
        BST* temporaryTree;
        if(tree->left == NULL) {
            temporaryTree = tree;
            tree = tree->right;
            free(temporaryTree);
        } else if(tree->right == NULL) {
            temporaryTree = tree;
            tree = tree->left;
            free(temporaryTree);
        } else {
            temporaryTree = tree->left;
            while(temporaryTree->right != NULL) {
                temporaryTree = temporaryTree->right;
            }
            tree->value = temporaryTree->value;
            temporaryTree->value = value;
            tree->left = removeElement(tree->left, value);
        }
    }

    return tree;
}
