#include <iostream>
using namespace std;

#define N 4 

bool column[N];           
bool diagLeft[2 * N];     
bool diagRight[2 * N];    
int board[N][N];          

bool placeQueen(int row) {
    if (row == N)
        return true;

    for (int col = 0; col < N; col++) {
        if (!column[col] && !diagLeft[row - col + N - 1] && !diagRight[row + col]) {
            board[row][col] = 1;
            column[col] = diagLeft[row - col + N - 1] = diagRight[row + col] = true;

            if (placeQueen(row + 1))
                return true;

            board[row][col] = 0;
            column[col] = diagLeft[row - col + N - 1] = diagRight[row + col] = false;
        }
    }

    return false;
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

int main() {
    for (int i = 0; i < N; i++) column[i] = false;
    for (int i = 0; i < 2 * N; i++) diagLeft[i] = diagRight[i] = false;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (placeQueen(0))
        printBoard();
    else
        cout << "No solution found.\n";

    return 0;
}
