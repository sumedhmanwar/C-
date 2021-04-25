#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

#include "Queue.h"

using namespace std;

int main() {
    Queue q;
    int queueSize;
    cin >> queueSize;
    q.createQueue(queueSize);

    string pushString = "PUSH";
    string popString = "POP";
    string end = "-1";
    string tempString;
    int tempData;

    while (1) {
        cin >> tempString;
        if (tempString == pushString) {
            cin >> tempData;
            q.pushQueue(tempData);
        } else if (tempString == popString) {
            q.popQueue();
        } else if (tempString == end) {
            break;
        } else {
            cout << "Invalid input!" << endl;
            cout << "Enter <-1> to end the program." << endl;
        }
    }
    return 0;
}
