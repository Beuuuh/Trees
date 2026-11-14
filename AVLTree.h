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
        void destroyTree(Node* node);
        void calculateBalance(Node* node);
        
        Node* doRotations(Node* node);
        Node* insertElement(Node* node, int value);
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
