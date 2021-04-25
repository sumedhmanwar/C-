#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#include "StackArr.h"


using namespace std;

int main() {
    // Take IO from file
    ifstream input("input.txt");
    streambuf *cinbuf = cin.rdbuf();
    cin.rdbuf(input.rdbuf());

    ofstream outpt("output.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(outpt.rdbuf());

    // main program
    StackArr s;
    int cap; // capacity of stack
    cin >> cap;
    s.createStack(cap);

    string pushString = "PUSH";
    string popString = "POP";
    string end = "-1";

    string operation;
    int data;

    while (1) {
        cin >> operation;
        if (operation == end) break;
        else if (operation == pushString) {
            cin >> data;
            s.stackPush(data);
        }
        else if (operation == popString) {
            s.stackPop();
        }
        else {
            cout << "Invalid input" << endl;
            cout << "Enter <-1> to end the program" << endl;
        }
    }

    // resetting IO
    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);
    return 0;
}
