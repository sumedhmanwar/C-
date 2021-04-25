#include <iostream>

#include "Hash.h"
using  namespace std;




int main() {
    int Bins;
    cout << "Enter no. of bins: ";
    cin >> Bins;
    Hash hashTable(Bins);

    for (int i = 0; i < 25; ++i) {
        hashTable.addEntry(i);
    }

    hashTable.deleteEntry(7);
    hashTable.deleteEntry(22);
    hashTable.printHash();
    return 0;
}
