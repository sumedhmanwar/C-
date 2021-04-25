#include <iostream>
#include <stdlib.h>

using namespace std;

class array{
private:
    int capacity;
    int size;
    int *arr;
public:
    void createArray(int cap);
    void addElement(int data);
    void printArray();
};





void array::createArray(int cap){
    capacity = cap;
    arr = new int[capacity];
    size = 0;
    for (int i = 0; i < capacity; ++i){
        arr[i] = -1;
    }
}






void array::addElement(int data){
    arr[size] = data;
    size++;
}




void array::printArray(){
    cout << "The array contains following nimbers :";
    for (int i = 0; i < size; ++i){
        cout << arr[i] << "  ";
    }
    cout << endl;
}












int main(){
    array a;
    int cap;
    int temp;
    cout << "Enter capacity :" << endl;
    cin >> cap;
    a.CreateArray(cap);
    cout << "Enter numbers :" <<endl;
    for (int i = 0; i < cap; ++i){
        cin >> temp;
        a.AddElement(temp);
    }
    a.PrintArray();

    return 0;
}














