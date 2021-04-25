#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#include "BST.h"

using namespace std;


int main() {
    // Redirect IO
    ifstream input("input.txt");
    streambuf *cinbuf = cin.rdbuf();
    cin.rdbuf(input.rdbuf());

    ofstream output("output.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(output.rdbuf());

    BST b;
    int enteredData;
    for (int i = 0; i < 15; ++i) {
        cin >> enteredData;
        b.insertData(enteredData);
    }
    b.inorderTraversal();
    b.findSuccesor(42);


    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);

    return 0;
}
