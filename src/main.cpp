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

    //player position
    int playerX = 1;
    int playerY = 1;

    for (int y = 0; y < map.size(); y++) {
        for (int x = 0; x < map[y].size(); x++) {
            if (x == playerX && y == playerY) {
                cout << '@'; // Draw player
            } else {
                cout << map[y][x]; // Draw map
            }
        }
        cout << endl;
    }

    return 0;
}