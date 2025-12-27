#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void drawMap(const vector<string>& map, int playerX, int playerY, int enemyX, int enemyY) {
    system(CLEAR);
    for (int y = 0; y < map.size(); y++) {
        for (int x = 0; x < map[y].size(); x++) {
            if (x == playerX && y == playerY) {
                cout << '@'; // Player character
            } else if (x == enemyX && y == enemyY) {
                cout << 'E'; // Enemy character
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

void moveEnemy(const vector<string>& map, int& enemyX, int& enemyY) {
    int direction = (rand() % 4);

    int newEnemyX = enemyX;
    int newEnemyY = enemyY;

    if (direction == 0) newEnemyY--;
    else if (direction == 1) newEnemyY++;
    else if (direction == 2) newEnemyX--;
    else if (direction == 3) newEnemyX++;

    // Try to move in the direction of the player
    if (!isWall(map, newEnemyX, newEnemyY)) {
        enemyX = newEnemyX;
        enemyY = newEnemyY;
    }
}

int main() {
    srand(time(nullptr));

    vector<string> map= {
        "####################",
        "#..................#",
        "#..................#",
        "#..................#",
        "####################"
    };

    //enemy position
    int enemyX = 10;
    int enemyY = 3;

    //player position
    int playerX = 1;
    int playerY = 1;
    
    while (true) {
        drawMap(map, playerX, playerY, enemyX, enemyY);

        if (processInput(cin.get(), playerX, playerY, map) == false) {
            break; // Exit game loop
        }
        moveEnemy(map, enemyX, enemyY);
    }
    return 0;
}