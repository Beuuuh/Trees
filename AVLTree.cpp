#include <iostream>
#include "./AVLTree.h"

AVL::AVL(int value) {
    Node *root = new Node();
    root->value = value;
    root->left = nullptr;
    root->right = nullptr;
    root->balance = 0;
}

int AVL::height(AVL::Node* tree) {
    Node* auxRoot = tree;
    int leftHeight = 0;
    int rightHeight = 0;

    if(isEmpty(auxRoot)) {
        return -1;
    } else {
        rightHeight = height(auxRoot->right);
        leftHeight = height(auxRoot->left);
        if(rightHeight > leftHeight) {
            return 1 + rightHeight;
        } else {
            return 1 + leftHeight;
        }
    }

}

bool AVL::isEmpty(Node* node) {
    if(node == nullptr) {
        return true;
    }
    return false;
}

