#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int rows = 10;
const int cols = 10;

struct Player {
    int row;
    int col;
};

struct Goal {
    int row;
    int col;
};

struct Maze {
    vector<vector<char>> grid;
    Player player;
    Goal goal;
};

void initializeMaze(Maze& maze) {
    maze.grid = {
        {'#', '#', '#', '#', '#','#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '.','.','#','#','#','#'},
        {'#', '.', '#', '.', '#','.','.','.','.','#'},
        {'#', '.', '.', '#','.','.','.','.','#','.','#'},
        {'#', '.', '#', '#', '.','.', '.', '#', '#', '#'},
         {'#', '#', '.', '.', '.','#', '#', '.', '#', '#'},
        {'#', '.', '.', '.', '#','.','.','#','.','#'},
        {'#', '.', '#', '#', '#','.','.','.','.','#'},
        {'#', '.', '.', '.','.','.','#','.','G','#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    maze.player = {1, 1}; // Player starting position
    maze.goal = {8, 8};   // Goal position
}

void displayMaze(const Maze& maze) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == maze.player.row && j == maze.player.col) {
                cout << 'P'; // Player position
            } else {
                cout << maze.grid[i][j];
            }
            cout << " ";
        }
        cout << endl;
    }
}

bool isGoalReached(const Maze& maze) {
    return (maze.player.row == maze.goal.row && maze.player.col == maze.goal.col);
}

bool isValidMove(const Maze& maze, int newRow, int newCol) {
    return (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && maze.grid[newRow][newCol] != '#');
}

void movePlayer(Maze& maze, int rowOffset, int colOffset) {
    int newRow = maze.player.row + rowOffset;
    int newCol = maze.player.col + colOffset;

    if (isValidMove(maze, newRow, newCol)) {
        maze.player.row = newRow;
        maze.player.col = newCol;
    }
}

int main() {
    Maze maze;
    initializeMaze(maze);

    cout << "Welcome to the Maze Game!" << endl;
    cout << "Use W-A-S-D to move the player ('P') to the goal ('.') in the maze." << endl;

    while (true) {
        displayMaze(maze);

        char move;
        cout << "Enter your move (W-A-S-D): ";
        cin >> move;

        switch (move) {
            case 'w': // Move up
                movePlayer(maze, -1, 0);
                break;
            case 'a': // Move left
                movePlayer(maze, 0, -1);
                break;
            case 's': // Move down
                movePlayer(maze, 1, 0);
                break;
            case 'd': // Move right
                movePlayer(maze, 0, 1);
                break;
            default:
                cout << "Invalid move. Try again." << endl;
                continue;
        }

        if (isGoalReached(maze)) {
            cout << "Congratulations! You reached the goal!" << endl;
            break;
        }
    }

    return 0;
}