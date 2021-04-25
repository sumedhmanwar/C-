#include <iostream>
#include <cstdlib>

using namespace std;



class DLLADT {
private:
    typedef struct Node {
        int data;
        struct Node* previos;
        struct Node* next;
    }Node;
    Node* root;

public:
    DLLADT();
    void insertNodee(int);
    DLLADT::Node* searchList(int);
    void deleteNode(int);
    void print();

};


