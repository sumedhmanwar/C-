#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#include "BST.h"

using namespace std;

BST::BST() {
    root = nullptr;
}

BST::Node* BST::createNode(int value) {
    Node* newNode;
    newNode = new Node;
    newNode->data = value;
    newNode->right = nullptr;
    newNode->left = nullptr;
    newNode->parent = nullptr;
    return newNode;
}

void BST::insertData(int value) {
    Node* newNode;
    newNode = createNode(value);
    if (root == nullptr) {
        root = newNode;
        return;
    }
    Node* temp = root;
    Node* target_parent = nullptr;
    while (temp != nullptr) {
        target_parent = temp;
        if (value < temp->data) { temp = temp->left; }
        else if (value > temp->data) { temp = temp->right; }
        else {
            cout << "Duplicate element" << endl;
            return;
        }
    }
    newNode->parent = target_parent;
    if (value < target_parent->data) target_parent->left = newNode;
    else target_parent->right = newNode;
}

void BST::inorder(BST::Node* ptr1) {
    if (ptr1 == nullptr) return;
    inorder(ptr1->left);
    cout << ptr1->data << " " << endl;
    inorder(ptr1->right);
}

void BST::inorderTraversal() {
    inorder(root);
}




void BST::preorder(BST::Node* ptr1) {
    if (ptr1 == nullptr) return;
    cout << ptr1->data << " " << endl;
    preorder(ptr1->left);
    preorder(ptr1->right);
}

void BST::preorderTraversal() {
    preorder(root);
}

void BST::postorder(BST::Node* ptr1) {
    if (ptr1 == nullptr) return;
    postorder(ptr1->left);
    postorder(ptr1->right);
    cout << ptr1->data << " " << endl;
}

void BST::postorderTraversal() {
    postorder(root);
}







void BST::destructer(BST::Node* ptr1) {
    if (ptr1 == nullptr) return;
    destructer(ptr1->left);
    destructer(ptr1->right);
    delete ptr1;
}

BST::~BST() {
    destructer(root);
}



// Search, GetMinimum of tree & succesor of node


BST::Node* BST::search(int value) {
    Node* temp;
    temp = root;
    while (temp != nullptr) {
        if (temp->data == value) return temp;
        else if (value < temp->data) temp = temp->left;
        else temp= temp->right;
    }
    return nullptr;
}

BST::Node* BST::getMinimum(BST::Node* subTreeRoot) {
    while (subTreeRoot->left != nullptr) subTreeRoot = subTreeRoot->left;
    return subTreeRoot;
}

BST::Node* BST::succesor(BST::Node* target) {
    if (target->right != nullptr) return getMinimum(target->right);
    // NULL parent condition i.e. root is biggest element
    if (target->parent == nullptr) return nullptr;
    // either succesor exist or not
    while (target->parent != nullptr && target != (target->parent)->left) {
        target = target->parent;
    }
   if (target->parent == nullptr) return nullptr; // target was biggest element
   else return (target->parent);
}

// public function

void BST::findSuccesor(int va   ) {
    Node* temp;
    temp = search(va);
    Node* target;
    target = succesor(temp);
    if (target == nullptr) {
        cout << "No succesor" << endl;
        return;
    } else cout << target->data << endl;
}



// Deleting functions

int BST::childCount(BST::Node* target) {
    /*
     * No child 00 -> 0
     * only left child -> 10
     * only right child -> 01 -> 1
     * Both chind ->11
     */
    int count = 0;
    if (target->left != nullptr) count += 10;
    if (target->right != nullptr) count += 1;
    return count;
}

void BST::swapValues(BST::Node* Node1, BST::Node* Node2) {
    int temp;
    temp = Node1->data;
    Node1->data = Node2->data;
    Node2->data = temp;
}
/*
BST::Node* BST::deleteNode(BST::Node* target) {
    // sigle element in whole tree
    if (childCount(target) == 0 && target == root) {
        delete root;
        root == nullptr;
    }

    Node* targetParent;
    targetParent = target->parent;
    // leaf node
    if (childCount(target) == 0) {
        // target is left child
        if (target == (target->parent)->left) {
            targetParent->left = nullptr;
            return target;
        }
        if (target == (target->parent)->right) {
            targetParent->right = nullptr;
            return target;
        }
    }
    // single child
    // target is left
    if (childCount(target) == 10) {
        if (childCount(targetParent) ==10) {
            targetParent->left = target->left;
            (target->left)->parent = targetParent;
            return target;
        }
        if (childCount(targetParent) == 1)
    }
}



*/








