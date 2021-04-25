#include <iostream>

using namespace std;


int* shellSort(int *arr, int cap, int sequenceValue) {
    int hole,i,j,k,l;
    i = 0;
    for (l = 0; l < sequenceValue; ++l) {
        //k = i;
        for (i = l + sequenceValue; i < cap; i += sequenceValue) {
            hole = arr[i];
            j = i;
            while (j > l && arr[j - sequenceValue] > hole) {
                arr[j] = arr[(j - sequenceValue)];
                j -= sequenceValue;
            }
            arr[j] = hole;
        }
    }
    return arr;
}


void printArray(int *arr, int cap) {
    for (int i = 0; i < cap; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shellSortUtil(int *arr, int cap, int sequenceValues) {
    //int sequenceValues;
    //cin >> sequenceValues;
    arr = shellSort(arr, cap, sequenceValues);
    printArray(arr, cap);
}



int main() {
    int cap;
    int *arr;
    int i;
    cin >> cap;
    arr = new int[cap];
    for (i = 0; i < cap ; ++i) {
        cin >> arr[i];
    }

    int NoOfSequenceValues;
    int sequenceValues;
    cin >> NoOfSequenceValues;
    for (int j = 0; j < NoOfSequenceValues; ++j) {
        cin >> sequenceValues;
        shellSortUtil(arr, cap, sequenceValues);
    }
    //shellSortUtil(arr, cap);

    return 0;
}




