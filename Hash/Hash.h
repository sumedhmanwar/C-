#include <iostream>

using namespace std;


class Hash {

private:
    int m;  //number of bins
    typedef struct Node {
        int data;
        struct Node* next;
        struct Node* previos;
    }Node;
    Hash::Node* hashBins;

public:
    Hash();
    explicit Hash(int);
    void addEntry(int);
    Hash::Node* searchEntry(int);
    void deleteEntry(int);
    void printHash();

};



