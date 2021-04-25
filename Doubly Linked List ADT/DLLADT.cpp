#include <iostream>
#include <stdlib.h>
#include "DLLADT.h"

using namespace std;

DLLADT::DLLADT() {
    root = nullptr;
}

void DLLADT::insertNodee(int value) {
    if (root == nullptr){
        root = new Node;
        root->data = value;
        root->next = root->previos = root;
    }

    // Adding node previos of root
    Node* tempPtr;  // yemporary pointer
    Node* temp = new Node ;  // Creating node foe insertion
    temp->data = value;

    // First handling temp's pointers
    temp->previos = root->previos;
    temp->next = root;

    // Now handling pointers pointing to temp
    (temp->previos)->next = temp;
    root->previos = temp;

}




DLLADT::Node* DLLADT::searchList(int value) {
    Node* temp;
    temp = root;
    if (root->data == value) return root;
    temp = temp->next;
    while (temp != root){
        if (temp->data == value) return temp;
        else temp = temp->next;
    }
    cout << "Error: " << value << " does not exist" << endl;
    return nullptr;
}




void DLLADT::deleteNode(int value) {
    Node* targetNode;
    targetNode = searchList(value);
    (targetNode->previos)->next = targetNode->next;
    (targetNode->next)->previos = targetNode->previos;
    delete targetNode;
}



void DLLADT::print() {
    Node* temp1;
    Node* temp2;
    temp1 = root;
    temp2 = root->previos;
    while (temp2 != temp1){
        cout << temp2->data << "  ";
        temp2 = temp2->previos;
    }
}

