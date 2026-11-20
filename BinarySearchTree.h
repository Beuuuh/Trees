typedef struct BST BST;

struct BST {
    BST* left;
    BST* right;
    int value;
};

BST* insertElement(BST* tree, int value);
BST* removeElement(BST* tree, int value);
BST* createEmptyTree();

int height(BST* tree);
int isEmpty(BST* tree);
int inTree(BST* tree, int value);
int leafSum(BST* tree);
int primeNodes(BST* tree);
int especificOddNodeAmount(BST* tree);
int especificPairNodeAmount(BST* tree);

void printTree(BST* tree);
void deleteTree(BST* tree);
