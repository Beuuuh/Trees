#include "stdint.h"

class AVL {
    private:
        struct Node {
            int value;
            int balance;
            Node* left;
            Node* right;
        };

        Node* root;

        int height(Node* node);

        bool inTree(Node* node, int value);

        void printTree(Node* node);
    public:
        int height();
        
        bool inTree(int value);
        bool isEmpty();

        void printTree();
        void insertElement(int value);
        void removeElement(int value);

        AVL(int value);
        ~AVL();
};
