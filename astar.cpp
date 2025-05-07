#include <iostream>
using namespace std;

const int MAX = 20; 
int grid[MAX][MAX]; 
int n; 

int g[MAX][MAX]; 
int h[MAX][MAX]; 
int f[MAX][MAX]; 

int parentX[MAX][MAX];
int parentY[MAX][MAX];


int openX[MAX * MAX], openY[MAX * MAX]; 
int closed[MAX][MAX]; 
int openCount; 

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int calculateH(int x, int y, int goalX, int goalY) {
    return abs(x - goalX) + abs(y - goalY);
}

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 && closed[x][y] == 0;
}


void addToOpen(int x, int y) {
    openX[openCount] = x;
    openY[openCount] = y;
    openCount++;
}

bool findLowestF(int& x, int& y) {
    if (openCount == 0) return false;
    int minF = 9999, index = -1;
    for (int i = 0; i < openCount; i++) {
        int fx = f[openX[i]][openY[i]];
        if (fx < minF) {
            minF = fx;
            index = i;
        }
    }
    x = openX[index];
    y = openY[index];
    for (int i = index; i < openCount - 1; i++) {
        openX[i] = openX[i + 1];
        openY[i] = openY[i + 1];
    }
    openCount--;
    return true;
}

void aStar(int startX, int startY, int goalX, int goalY) {

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            g[i][j] = 9999;
            h[i][j] = calculateH(i, j, goalX, goalY);
            f[i][j] = 9999;
            closed[i][j] = 0;
            parentX[i][j] = -1;
            parentY[i][j] = -1;
        }

    openCount = 0;
    g[startX][startY] = 0;
    f[startX][startY] = h[startX][startY];
    addToOpen(startX, startY);


    while (openCount > 0) {
        int currentX, currentY;
        if (!findLowestF(currentX, currentY)) break;

        closed[currentX][currentY] = 1;

        if (currentX == goalX && currentY == goalY) {
            cout << "Path found!\n";
            int pathX[MAX * MAX], pathY[MAX * MAX], pathLen = 0;
            int x = goalX, y = goalY;
            while (x != -1 && y != -1) {
                pathX[pathLen] = x;
                pathY[pathLen] = y;
                pathLen++;
                int px = parentX[x][y], py = parentY[x][y];
                x = px;
                y = py;
            }
            cout << "Path (from start to goal): ";
            for (int i = pathLen - 1; i >= 0; i--)
                cout << "(" << pathX[i] << "," << pathY[i] << ") ";
            cout << "\n";
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newX = currentX + dx[i];
            int newY = currentY + dy[i];
            if (isValid(newX, newY)) {
                int newG = g[currentX][currentY] + 1;
                if (newG < g[newX][newY]) {
                    g[newX][newY] = newG;
                    f[newX][newY] = g[newX][newY] + h[newX][newY];
                    parentX[newX][newY] = currentX;
                    parentY[newX][newY] = currentY;
                    addToOpen(newX, newY);
                }
            }
        }
    }
    cout << "No path found!\n";
}

int main() {
    
    cout << "Enter grid size (n for n x n, max 20): ";
    cin >> n;
    if (n <= 0 || n > MAX) {
        cout << "Invalid size!\n";
        return 1;
    }

    cout << "Enter grid (" << n << "x" << n << ", 0 = open, 1 = wall):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != 0 && grid[i][j] != 1) {
                cout << "Invalid cell value! Use 0 or 1.\n";
                return 1;
            }
        }

    int startX, startY, goalX, goalY;
    cout << "Enter start position (x y, 0 to " << n-1 << "): ";
    cin >> startX >> startY;
    cout << "Enter goal position (x y, 0 to " << n-1 << "): ";
    cin >> goalX >> goalY;

    if (startX < 0 || startX >= n || startY < 0 || startY >= n ||
        goalX < 0 || goalX >= n || goalY < 0 || goalY >= n) {
        cout << "Start or goal out of bounds!\n";
        return 1;
    }
    if (grid[startX][startY] == 1 || grid[goalX][goalY] == 1) {
        cout << "Start or goal is on a wall!\n";
        return 1;
    }

    cout << "\nGrid (0 = open, 1 = wall):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }

    cout << "Finding path from (" << startX << "," << startY << ") to (" << goalX << "," << goalY << "):\n";
    aStar(startX, startY, goalX, goalY);

    return 0;
}