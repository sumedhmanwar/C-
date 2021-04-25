#include <iostream>
#include <cstdlib>
#include <fstream>
///////////   https://stackoverflow.com/questions/10150468/how-to-redirect-cin-and-cout-to-files
using namespace std;


int main() {
    ifstream input("input.txt");
    streambuf *cinbuf = cin.rdbuf();
    cin.rdbuf(input.rdbuf());

    ofstream output("output.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(output.rdbuf());

    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
    bool c, d;
    c = true;
    d = false;
    if (c) cout << d << endl;

    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);

    return 0;
}
