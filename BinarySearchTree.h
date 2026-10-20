typedef struct BST BST;

struct BST {
    BST* left;
    BST* right;
    int value;
};

BST* insertElement();
BST* removeElement();
BST* createEmptyTree();

int height(BST* tree);
int isEmpty(BST* tree);
int inTree(BST* tree);

void printTree(BST* tree);
void deleteTree(BST* tree);
