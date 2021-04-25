#include <iostream>
#include <cstdlib>
#include "DLLADT.h"

using namespace std;

int main() {
    DLLADT d;
    for (int i = 1; i <= 10; i++){
        d.insertNodee(i);
    }
    d.deleteNode(5);
    d.print();
    return 0;
}
