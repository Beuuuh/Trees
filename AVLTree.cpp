#include <iostream>
#include "./AVLTree.h"

AVL::AVL(int value) {
    Node *root = new Node();
    root->value = value;
    root->left = nullptr;
    root->right = nullptr;
    root->balance = 0;
}

bool AVL::isEmpty() {
    return this->root == nullptr;
}

int AVL::height() {
    return height(this->root);
}

int AVL::height(Node* node) {
    if(node == nullptr) {
        return -1;
    } else {
        int rightHeight = height(node->right);
        int leftHeight = height(node->left);
        
        if (rightHeight > leftHeight) {
            return 1 + rightHeight;
        } else {
            return 1 + leftHeight;
        }
    }
}

