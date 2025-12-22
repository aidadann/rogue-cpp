#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

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
    
    while (true) {
        system(CLEAR);

        cout << endl;
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

        cout << "\nMove(wasd), quit(q): ";
        char input;
        cin >> input;

        int newPlayerX = playerX;
        int newPlayerY = playerY;

        if (input == 'w') newPlayerY--;
        else if (input == 's') newPlayerY++;
        else if (input == 'a') newPlayerX--;
        else if (input == 'd') newPlayerX++;
        else if (input == 'q') break;
        // Check for collisions with walls
        if (map[newPlayerY][newPlayerX] != '#') {
            playerX = newPlayerX;
            playerY = newPlayerY;
        }
    }

    return 0;
}