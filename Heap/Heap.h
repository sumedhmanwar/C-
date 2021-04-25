#include <iostream>

using namespace std;


class Heap {
//private:
public:
    int* arr;
    int totalCap;
    int size;
//public:
    Heap();
    void createHeap(int );

    int parent(int);
    int leftChild(int);
    int rightChild(int);
    void swap(int ,int );
    void heapifyBU();
    void heapifyTD();

    void addKey(int );
    void deleteKey();
    void heapSort();

    void printHeap();
    void checkHeap();

};

