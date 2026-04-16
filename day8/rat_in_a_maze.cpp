#include <iostream>
#include <vector>

using namespace std;

bool solveMaze(const vector<vector<int>>& maze, vector<vector<int>>& path, int x, int y, int n) {
    if (x == n - 1 && y == n - 1 && maze[x][y] == 1) {
        path[x][y] = 1;
        return true;
    }

    if (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && path[x][y] == 0) {
        path[x][y] = 1;

        if (solveMaze(maze, path, x + 1, y, n)) {
            return true;
        }

        if (solveMaze(maze, path, x, y + 1, n)) {
            return true;
        }

        if (solveMaze(maze, path, x - 1, y, n)) {
            return true;
        }

        if (solveMaze(maze, path, x, y - 1, n)) {
            return true;
        }

        path[x][y] = 0;
    }

    return false;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    int n = static_cast<int>(maze.size());
    vector<vector<int>> path(n, vector<int>(n, 0));

    if (solveMaze(maze, path, 0, 0, n)) {
        cout << "Path found:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << path[i][j] << ' ';
            }
            cout << '\n';
        }
    } else {
        cout << "No path exists.\n";
    }

    return 0;
}
