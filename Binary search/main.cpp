#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <algorithm>
#include <time.h>

using namespace std;


int binarySearch(int *arr,int left, int right, int data) {
    int mid = left + ((right - left) /2);
    if (right < left) return (-1);
    if (arr[mid] == data) return mid;
    if (data < arr[mid] ) return binarySearch(arr, left, (mid-1), data);
    else return binarySearch(arr, (mid+1), right, data);
}





int main() {
    //Redirect IO
    ifstream input("input.txt");
    streambuf *cinbuf = cin.rdbuf();
    cin.rdbuf(input.rdbuf());

    ofstream output("output.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(output.rdbuf());

    // Main code

    int* arr;
    arr = new int[15];
    for (int i = 0; i < 15; ++i) {
        cin >> arr[i];
    }

    int index;
    index = binarySearch(arr, 0, 14, 62);
    cout << index << endl;


    // End of main program
    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);
    return 0;
}


