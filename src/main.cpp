#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> map= {
        "####################",
        "#..................#",
        "#..................#",
        "#..................#",
        "####################"
    };

    for (const string& row : map) {
        cout << row << endl;
    }

    return 0;
}