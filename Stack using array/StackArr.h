#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

class StackArr {
private:
    int* arr;
    int capacity;
    int topIndex;
public:
    StackArr();
    //StackArr(int);
    virtual ~StackArr();
    void createStack(int);
    bool isEmpty();
    bool isFull();
    void stackPush(int);
    void stackPop();
    void stackPrint();
};

