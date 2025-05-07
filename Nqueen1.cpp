#include <iostream>
using namespace std;

bool column[100];               
bool diagLeft[200];             
bool diagRight[200];            
int board[100][100];            

bool placeQueen(int row, int N) {
    if (row == N)
        return true;

    for (int col = 0; col < N; col++) {

        if (!column[col] && !diagLeft[row - col + N - 1] && !diagRight[row + col]) {
            board[row][col] = 1;
            column[col] = diagLeft[row - col + N - 1] = diagRight[row + col] = true;

            
            if (placeQueen(row + 1, N))
                return true;

            
            board[row][col] = 0;
            column[col] = diagLeft[row - col + N - 1] = diagRight[row + col] = false;
        }
    }

    return false;
}


void printBoard(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

int main() {
    int N;
    cout << "Enter the value of N (size of the board and number of queens): ";
    cin >> N;

    
    for (int i = 0; i < N; i++) column[i] = false;
    for (int i = 0; i < 2 * N; i++) diagLeft[i] = diagRight[i] = false;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    
    if (placeQueen(0, N))
        printBoard(N);  
    else
        cout << "No solution found.\n";  

    return 0;
}
