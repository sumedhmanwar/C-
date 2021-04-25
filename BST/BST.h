#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;



class BST {
private:
    typedef struct Node{
        int data;
        struct Node* left;
        struct Node* right;
        struct Node* parent;
    }Node;
    Node* root;
    void destructer(BST::Node*);
    void inorder(BST::Node*);
    void preorder(BST::Node*);
    void postorder(BST::Node*);
    // findSuccesor functions
    BST::Node* search(int);
    BST::Node* getMinimum(BST::Node*);
    BST::Node* succesor(BST::Node*);
    // deletevalue function
    int childCount(BST::Node*);
    void swapValues(BST::Node*, BST::Node*);
    //BST::Node* deleteNode(BST::Node*);
public:
    BST();
    virtual ~BST();
    BST::Node* createNode(int);
    void insertData(int);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    void findSuccesor(int);
};


