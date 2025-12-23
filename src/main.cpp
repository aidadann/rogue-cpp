#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void drawMap(const vector<string>& map, int playerX, int playerY) {
    system(CLEAR);
    for (int y = 0; y < map.size(); y++) {
        for (int x = 0; x < map[y].size(); x++) {
            if (x == playerX && y == playerY) {
                cout << '@'; // Player character
            } else {
                cout << map[y][x];
            }
        }
        cout << endl;
    }
    cout << "Use WASD to move, Q to quit." << endl;
}

bool isWall(const vector<string>& map, int x, int y) {
    return map[y][x] == '#';
}

bool processInput(char input, int& playerX, int& playerY, const vector<string>& map) {
    int newPlayerX = playerX;
    int newPlayerY = playerY;

    if (input == 'w') newPlayerY--;
    else if (input == 's') newPlayerY++;
    else if (input == 'a') newPlayerX--;
    else if (input == 'd') newPlayerX++;
    else if (input == 'q') return false; // Quit game

    // Check for collisions with walls
    if (!isWall(map, newPlayerX, newPlayerY)) {
        playerX = newPlayerX;
        playerY = newPlayerY;
    }
    return true;
}

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
        drawMap(map, playerX, playerY);

        if (processInput(cin.get(), playerX, playerY, map) == false) {
            break; // Exit game loop
        }
    }
    return 0;
}