#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <algorithm>
#include <time.h>
///////////
using namespace std;


int main() {
    // Redirect IO
    ifstream input("input.txt");
    streambuf *cinbuf = cin.rdbuf();
    cin.rdbuf(input.rdbuf());

    ofstream output("output.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(output.rdbuf());

    // Main code
    int arr[15];
    srand(time(0));
    for (int i = 0; i < 15; ++i) {
        arr[i] = (rand() % 100);
    }
    //sort(arr, arr+15);

    for (int i = 0; i < 15; ++i) {
        cout << arr[i] << endl;
    }

    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);
    return 0;
}
