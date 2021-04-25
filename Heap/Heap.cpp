#include <iostream>
#include "Heap.h"

using namespace std;

Heap::Heap() {
    arr = nullptr;
    totalCap = 0;
    size = 0;
}

void Heap::createHeap(int cap) {
    arr = new int[(cap+1)];
    totalCap = cap;
    size = 0;
    arr[0] = INT_FAST32_MIN;
    for (int i = 1; i <= totalCap; ++i) {
        arr[i] = INT_FAST32_MAX;
    }
}


int Heap::parent(int i) {
    return (i/2);
}
int Heap::leftChild(int i) {
    return (2*i);
}
int Heap::rightChild(int i) {
    return ((2*i) + 1);
}
void Heap::swap(int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


void Heap::heapifyBU() {
    //checkHeap();
    //cout << "Heap is :";
    //printHeap();
    int lastInt;
    lastInt = (size/2);
    int iter,temp;
    iter = (size/2);
    if (size <= 1) return;
    while (iter >= 1) {
        if (leftChild(iter) > size) {
            iter--;
            continue;
        }
        else if (arr[leftChild(iter)] > arr[iter]) {
            swap(leftChild(iter), iter);
        }
        if (rightChild(iter) > size) {
            iter--;
            continue;
        }
        else if (arr[rightChild(iter)] > arr[iter]) {
            swap(rightChild(iter), iter);
        }
        iter--;
    }
}

void  Heap::heapifyTD() {
    //checkHeap();
    //cout << "Heap is :";
    //printHeap();
    int lastInt;
    lastInt = (size/2);
    int iter,temp;
    iter = 1;
    if (size <= 1) return;
    while (iter <= size) {
        if (leftChild(iter) > size) {
            iter++;
            continue;
        }
        else if (arr[leftChild(iter)] > arr[iter]) {
            swap(leftChild(iter), iter);
        }
        if (rightChild(iter) > size) {
            iter++;
            continue;
        }
        else if (arr[rightChild(iter)] > arr[iter]) {
            swap(rightChild(iter), iter);
        }
        iter++;
    }

}


void Heap::addKey(int key) {
    size++;
    arr[size] = key;
    heapifyBU();
    checkHeap();
    //cout << "Size is " << size << endl;
}

void Heap::deleteKey() {
    //cout << "Size is " << size << " ";
    cout << arr[1] <<" ";
    //int k = arr[size];
    arr[1] = arr[size];
    size--;
    //checkHeap();
    //cout << "Heap is :";
    //printHeap();
    heapifyTD();
    checkHeap();
    //cout << "Heap is :";
    //printHeap();
    //cout << "Size is " << size << " ";
}

void Heap::heapSort() {
    //int temp = size;
    while (size > 0) {
        deleteKey();
    }
    cout << endl;
}





void Heap::printHeap() {
    //cout << size << endl;
    for (int i = 1; i <= size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void Heap::checkHeap() {
    int temp = size;
    for (int i = temp; i > 1; --i) {
        if (arr[parent(i)] < arr[i]) {
            cout << "Error " << arr[i] << endl;
        }
    }
}









