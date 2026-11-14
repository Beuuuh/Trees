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

bool AVL::inTree(int value) {
    return inTree(this->root, value);
}

bool AVL::inTree(Node* node, int value) {
    if(node == nullptr) {
        return false;
    } else if(node->value <= value) {
        return AVL::inTree(node->left, value);
    } else if(node->value > value) {
        return AVL::inTree(node->right, value);
    } else {
        return true;
    }
}

void AVL::printTree() {
    printTree(this->root);
    return;
}

void AVL::printTree(Node* node) {
    if(node == nullptr) {
        return;
    }

    printTree(node->left);
    printTree(node->right);
    std::cout << node->value;
}

AVL::~AVL() {
    AVL::destroyTree(this->root);
}

void AVL::destroyTree(Node* node) {
    if(node == nullptr) {
        return;
    }

    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

void AVL::insertElement(int value) {
    this->root = insertElement(this->root, value);
}

AVL::Node* AVL::insertElement(Node* node, int value) {
    if(node == nullptr) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->right = nullptr;
        newNode->left = nullptr;
        newNode->balance = 0;
        return newNode;
    } else if(node->value > value) {
        node->left = AVL::insertElement(node->left, value);
        calculateBalance(node);
        return node;
    } else if(node->value <= value) {
        node->right = AVL::insertElement(node->right, value);
        calculateBalance(node);
        return doRotations(node);
    }
}

void AVL::calculateBalance(Node* node) {
    if(node == nullptr) {
        return;
    }

    calculateBalance(node->left);
    calculateBalance(node->right);
    int rightHeight = height(node->right);
    int leftHeight = height(node->left);
    node->balance = rightHeight - leftHeight;
}

AVL::Node* AVL::doRotations(Node* node) {
    if(node->balance < 2 && node->balance > -2) {
        return node;
    } else if(node->balance == 2) {
        Node* father = node;
        Node* child = node->right;
        Node* abandonedChild = child->left;
        if(child->balance == 1) {
            father->right = abandonedChild;
            child->left = father;
            calculateBalance(node);
            return child;
        }

        if(child->balance == -1) {
            Node* father = node;
            Node* child = node->right;
            Node* childsChild = child->left;

            //rotations
            child->left = childsChild->right;
            childsChild->right = child;
            father->right = childsChild->left;
            childsChild->left = father;
            calculateBalance(node);
            return childsChild;
        }
    } else if(node->balance == -2) {
        Node* father = node;
        Node* child = node->left;

        if(child->balance == -1) {
            father->left = child->right;
            child->right = father;
            calculateBalance(node);
            return child;
        } 
        
        if(child->balance == 1) {
            Node* childsChild = child->right;
            child->right = childsChild->left;
            father->left = childsChild->right;
            childsChild->left = child;
            childsChild->right = father;
            calculateBalance(node);
            return childsChild;
        }
    }
}
