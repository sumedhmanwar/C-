#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

#include "Queue.h"

using namespace std;

Queue::Queue() {
    capacity = 0;
    head = tail = 0;
    arr = nullptr;
}

Queue::~Queue() {
    delete arr;
}

void Queue::createQueue(int cap) {
    capacity = cap;
    capacity++;
    arr = new int[capacity];
    head = 0;
    tail = 0;
}





int Queue::cAdd(int value) {
    if (value == (capacity-1)) return 0;
    else return (value + 1);
}

bool Queue::isFull() {
    if (head == cAdd(tail)) return true;
    else return false;
}

bool Queue::isEmpty() {
    if (head == tail) return true;
    else return false;
}





void Queue::pushQueue(int value) {
    if (isFull()) {
        cout << "Queue full!" << endl;
        return;
    }
    arr[tail] = value;
    tail = cAdd(tail);
    return;
}

void Queue::popQueue() {
    if (isEmpty()) {
        cout << "Empty queue!" << endl;
        return;
    }
    cout << arr[head] << endl;
    head = cAdd(head);
}










