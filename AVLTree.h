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
    public:
        AVL* insertElement(AVL* tree, int value);
        AVL* removeElement(AVL* tree, int value);

        int height(AVL::Node* tree);
        int inTree(AVL* tree, int value);

        bool isEmpty(AVL::Node* tree);

        void printTree(AVL* tree);

        AVL(int value);
        ~AVL();
};
