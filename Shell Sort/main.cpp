#include <iostream>

using namespace std;

class shell {
public:
    int *array;
    int cap;
    shell();
    void createArray();
    void shellSort();
    void printArray();

};

shell::shell() {
    array = nullptr;
    cap = 0;
}

void shell::createArray() {
    //int size, i;
    cin >> cap;
    array = new int[cap];
    for (int j = 0; j < cap; ++j) {
        cin >> array[j];
    }
}

void shell::shellSort() {
    int totalGapSequence, gapSequenceSize;
    int i,j,k, hple;
    i=j=k=0;
    cin >> totalGapSequence;
    for (int z = 0; z < totalGapSequence; ++z) {
        cin >> gapSequenceSize;
        for (i = 0; i<gapSequenceSize; i++) {
            for (j = i+gapSequenceSize; j< cap; j = j+gapSequenceSize) {
                hple = array[j];
                k=j;
                while (k>i && array[k-gapSequenceSize] > hple) {
                    array[k] = array[k-gapSequenceSize];
                    k = k- gapSequenceSize;
                }
                array[k] = hple;
            }
        }
        printArray();
    }
}

void shell::printArray() {
    for (int i = 0; i < cap; ++i) {
        cout << array[i] << " ";
    }
    cout    << endl;
}

int main() {
    shell shellSorting;
    shellSorting.createArray();
    shellSorting.shellSort();

    return 0;
}
