#include <iostream>
#include "Hash.h"

using namespace std;

Hash::Hash() {
    m = 1;
    hashBins = nullptr;
}

Hash::Hash(int Bins) {
    m = Bins;
    //Hash::Node *hasIndex[m];
    //hashBins = hasIndex;
    hashBins = new Hash::Node[m];
    for (int i = 0; i < m; ++i) {
        hashBins[i].data = i;
        hashBins[i].previos = nullptr;
        hashBins[i].next = nullptr;
    }
}
// search if its already there
void Hash::addEntry(int n) {
    Hash::Node* temporary;
    temporary = searchEntry(n);
    if (temporary != nullptr) {
        cout << "Element alrady present" << endl;
        return;
    }
    Hash::Node* newNode;
    newNode = new Hash::Node;
    newNode->data = n;
    newNode->next = nullptr;
    newNode->previos = nullptr;

    int BinValue = n % m;
    // No element in current bin
    if (hashBins[BinValue].next == nullptr) {
        newNode->previos = &hashBins[BinValue];
        hashBins[BinValue].next = newNode;
        return;
    }
    newNode->next = hashBins[BinValue].next;
    newNode->previos = &hashBins[BinValue];
    (newNode->next)->previos = newNode;
    hashBins[BinValue].next = newNode;
}

//void Hash::searchEntry(int) {}

Hash::Node* Hash::searchEntry(int n) {
    int bin = n % m;
    Hash::Node* target;
    target = hashBins[bin].next;
    while (target != nullptr) {
        if (target->data == n) return target;
        target = target->next;
    }
    return nullptr;
}

void Hash::deleteEntry(int n) {
    Hash::Node *target;


    // target at head
    int bin = n % m;
    if ((hashBins[bin].next)->data == n) {
        target = hashBins[bin].next;
        hashBins[bin].next = (hashBins[bin].next)->next;
        (hashBins[bin].next)->previos = &hashBins[bin];
        delete target;
        return;
    } else {
        target = searchEntry(n);
        if (target == nullptr) return;
        (target->previos)->next = target->next;
        (target->next)->previos = target->previos;
        delete target;
    }
}



void Hash::printHash() {
    int bin = m;
    Hash::Node *temp;
    temp = nullptr;
    for (int i = 0; i < bin; ++i) {
        temp = hashBins[i].next;
        cout << "bin " << i << "-> ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout <<endl;
    }
}

