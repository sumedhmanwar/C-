#include <cstdlib>
#include <fstream>

#include <iostream>
#include "Heap.h"

using namespace std;


int main() {
    ifstream input("input.txt");
    streambuf *cinbuf = cin.rdbuf();
    cin.rdbuf(input.rdbuf());

    ofstream output("output.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(output.rdbuf());



    Heap h;
    h.createHeap(100);
    int temp, n;
    cin >> n;
    //h.printHeap();
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        h.addKey(temp);
    }

    h.printHeap();
    h.heapSort();

//    cout << h.deleteKey();
//    h.printHeap();
//    h.deleteKey();
//    h.printHeap();


    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);


    return 0;
}
