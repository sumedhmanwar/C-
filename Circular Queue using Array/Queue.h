#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

class Queue {
private:
    int capacity;
    int* arr;
    int head;
    int tail;
public:
    Queue();
    virtual ~Queue();
    void createQueue(int);
    int cAdd(int);
    bool isFull();
    bool isEmpty();
    void pushQueue(int);
    void popQueue();
    //void printQueue();
};



