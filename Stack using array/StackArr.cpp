#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#include "StackArr.h"

using namespace std;


StackArr::StackArr() {
    arr = nullptr;
    capacity = 0;
    topIndex = -1;
}
/*
StackArr::StackArr(int cap) {
    capacity = cap;
    arr = new int[capacity];
    topIndex = -1;
}
*/
StackArr::~StackArr() {
    delete arr;
    cout << "Destructor is called" << endl;
}

void StackArr::createStack(int cap) {
    capacity = cap;
    arr = new int[capacity];
    topIndex = -1;
}




bool StackArr::isEmpty() {
    if (topIndex == -1) return true;
    else return false;
}

bool StackArr::isFull() {
    if (topIndex == (capacity - 1)) return true;
    else return false;
}




void StackArr::stackPush(int value ) {
    if (isFull()) {
        cout << "Stack full!" << endl;
        return;
    }
    topIndex++;
    arr[topIndex] = value;
}

void StackArr::stackPop() {
    if (isEmpty()) {
        cout << "Empty stck. Nothing to pop." << endl;
        return;
    }
    topIndex--;
    cout << arr[topIndex+1] << endl;
}




void StackArr::stackPrint() {
    if (isEmpty()) {
        cout << "Empty stack!" << endl;
        return;
    }
    for (int i = 0; i <= topIndex; ++i) {
        cout << arr[i] << endl;
    }
}



