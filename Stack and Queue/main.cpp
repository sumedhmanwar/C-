/*
 * Stack and Queue implemention
 * This implementation is made anallogous to a vector
 *
 * |front| -> ... -> |back|
 * Stack:
 *       |Bottom| root -> element1 -> element2 -> ...
 *       pushStack <-> pushBack
 *       popStack <-> popBack
 * Queue:
 *      ... -> root -> element1 -> element2 -> ...
 *      pushQueue <-> pushFront
 *      popQueue <-> popBack
 */





#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

class StackQueue{
private:
    typedef struct Node{
        int data;
        struct Node* next;
    }Node;
    Node* root;
    int capacity;
    int size;
    // Commin functions
    void create(int); // Sets root to null and argument to capacity
    StackQueue::Node* createNode(int); // returns node pointer with given value as data
    bool isFull();
    bool isEmpty();
    // push pop functions
    void pushBack(int);
    void popBack();
    void pushFront(int);
public:
    StackQueue();
    // Stack functions
    void createStack(int);
    void pushStack(int );
    void popStack();
    // Queue functions
    void createQueue(int);
    void pushQueue(int);
    void popQueue();
};




/* Finction implementation */

// Private finctions

// Common functions
void StackQueue::create(int cap) {
    root = nullptr;
    size = 0;
    capacity = cap;
}

StackQueue::Node* StackQueue::createNode(int value) {
    Node* newNode;
    newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

bool StackQueue::isFull() {
    if (capacity == (-1)) return false;
    else if (size == capacity) return true;
    else { return false; }
}

bool StackQueue::isEmpty() {
    if (root == nullptr) return true;
    else return false;
}

// push pop functions
void StackQueue::pushBack(int value) { // Add node at end
    if (isFull()) {
        cout << "capacity full" << endl;
        return;
    }
    size++;
    // Creting node
    Node* newNode;
    newNode = createNode(value);

    // Empty case
    if (root == nullptr){
        root = newNode;
        return;
    }

    // Non Empty case
    Node* temp;
    temp = root;
    while (temp->next != nullptr) temp = temp->next; // send temp to end of list
    temp->next = newNode;
}

void StackQueue::popBack() {
    if (isEmpty()) {
        cout << "No values available!" << endl;
        return;
    }
    size--;
    Node* temp = root;
    //  Single element
    if ((root->next) == nullptr) {
        cout << root->data << endl;
        delete root;
        root = nullptr;
        return;
    } else {   // Multiple elements
        // More than one elements
        while ((temp->next)->next != nullptr) temp = temp->next; // send temp to last secon element
        cout << (temp->next)->data << endl;
        delete (temp->next); // delete last element
        temp->next = nullptr;
    }
}

void StackQueue::pushFront(int value) {
    if (isFull()) {
        cout << "full!" << endl;
        return;
    }
    size++;
    // Creting node
    Node* newNode;
    newNode = createNode(value);

    // Empty case
    if (root == nullptr) {
        root = newNode;
        return;
    }

    // Non Empty case
    newNode->next = root;
    root = newNode;
}

// public functions
StackQueue::StackQueue() {
    root = nullptr;
    capacity = 0;
    size = 0;
}

// Stack functions
void StackQueue::createStack(int cap) {
    create(cap);
}

void StackQueue::pushStack(int value) {
    pushBack(value);
}

void StackQueue::popStack() {
    popBack();
}

// Queue functions
void StackQueue::createQueue(int cap) {
    create(cap);
}

void StackQueue::pushQueue(int value) {
    pushFront(value);
}

void StackQueue::popQueue() {
    popBack();
}



// Main function

int main() {
    cout << "Welcome to Stack and Queue program" << endl;
    cout << "Enter <1> for Stack and <2> for queue" << endl;
    cout << "Enter value :";
    StackQueue sq;
    int type, cap;
    cin >> type;
    cout << "Choose capacity of your structure. Enter <-1> for no limit" << endl;
    cout << "Enter capacity :";
    cin >> cap;
    if (type ==1) sq.createStack(cap);
    else if (type ==2) sq.createQueue(cap);
    else return 0;
    cout << "Enter <PUSH value> to push value on structure" << endl;
    cout << "Enter <POP> to pop a value" << endl;
    cout << "Enter <END> to end the program." << endl;

    string action;
    int tempValue;
    string pushString = "PUSH";
    string popString = "POP";
    string end = "END";

    while (1) {
        if (type ==1) {
            cin >> action;
            if (action == pushString) {
                cin >> tempValue;
                sq.pushStack(tempValue);
            } else if (action == popString) sq.popStack();
            else if (action == end) break;
            else {
                cout << "Invalid input!" << endl;
                cout << "Enter <END> to end the program." << endl;
            }
        }
        else if (type ==2) {
            cin >> action;
            if (action == pushString) {
                cin >> tempValue;
                sq.pushQueue(tempValue);
            } else if (action == popString) sq.popQueue();
            else if (action == end) break;
            else {
                cout << "Invalid input!" << endl;
                cout << "Enter <END> to end the program." << endl;
            }
        }
        else {
            cout << "Wrong input" << endl;
            cout << "End of program" << endl;
        }
    }
    return 0;
}
