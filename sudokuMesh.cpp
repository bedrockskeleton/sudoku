#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

class Sudoku {
public:
    int** mat;
    int N;
    int SRN;
    int K;

    Sudoku(int N, int K)
    {
        this->N = N;
        this->K = K;
        double SRNd = sqrt(N);
        SRN = (int)SRNd;
        mat = new int*[N];
        for (int i = 0; i < N; i++) {
            mat[i] = new int[N];
            memset(mat[i], 0, N * sizeof(int));
        }
    }

    void fillValues()
    {
        fillDiagonal();
        fillRemaining(0, SRN);
        removeKDigits();
    }

    void fillDiagonal()
    {
        for (int i = 0; i < N; i = i + SRN) {
            fillBox(i, i);
        }
    }

    bool unUsedInBox(int rowStart, int colStart, int num)
    {
        for (int i = 0; i < SRN; i++) {
            for (int j = 0; j < SRN; j++) {
                if (mat[rowStart + i][colStart + j] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    void fillBox(int row, int col)
    {
        int num;
        for (int i = 0; i < SRN; i++) {
            for (int j = 0; j < SRN; j++) {
                do {
                    num = randomGenerator(N);
                } while (!unUsedInBox(row, col, num));
                mat[row + i][col + j] = num;
            }
        }
    }

    int randomGenerator(int num)
    {
        return rand() % num + 1;
    }

    bool CheckIfSafe(int i, int j, int num)
    {
        return (
            unUsedInRow(i, num) && unUsedInCol(j, num)
            && unUsedInBox(i - i % SRN, j - j % SRN, num));
    }

    bool unUsedInRow(int i, int num)
    {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] == num) {
                return false;
            }
        }
        return true;
    }

    bool unUsedInCol(int j, int num)
    {
        for (int i = 0; i < N; i++) {
            if (mat[i][j] == num) {
                return false;
            }
        }
        return true;
    }

    bool fillRemaining(int i, int j)
    {
        if (j >= N && i < N - 1) {
            i = i + 1;
            j = 0;
        }
        if (i >= N && j >= N) {
            return true;
        }
        if (i < SRN) {
            if (j < SRN) {
                j = SRN;
            }
        } else if (i < N - SRN) {
            if (j == (int)(i / SRN) * SRN) {
                j = j + SRN;
            }
        } else {
            if (j == N - SRN) {
                i = i + 1;
                j = 0;
                if (i >= N) {
                    return true;
                }
            }
        }
        for (int num = 1; num <= N; num++) {
            if (CheckIfSafe(i, j, num)) {
                mat[i][j] = num;
                if (fillRemaining(i, j + 1)) {
                    return true;
                }
                mat[i][j] = 0;
            }
        }
        return false;
    }

    void removeKDigits()
    {
        int count = K;
        while (count != 0) {
            int cellId = randomGenerator(N * N) - 1;
            int i = (cellId / N);
            int j = cellId % N;
            if (mat[i][j] != 0) {
                count--;
                mat[i][j] = 0;
            }
        }
    }

    void printSudoku()
    {
        int yi = 0;
        int limit = 0;
        for (int i = 0; i < N; i++) {
            int xi = 0;
            for (int j = 0; j < N; j++) {
                if (xi == SRN) {
                    cout << "┃ ";
                    xi = 0;
                }
                cout << to_string(mat[i][j]) + " ";
                ++xi;
                Sleep(10);
            }
            cout << endl;
            ++yi;
            if (yi == SRN && limit <= SRN-2) {
                printSep();
                yi = 0;
                ++limit;
            }
        }
        cout << endl;
    }

    void printSep()
    {
        int amount = N*2+((SRN-1));
        int c = 1;
        int i;
        for (i = 0; i <= amount; ++i) {
            if (c == ((SRN*2)+1)) {
                cout << "╋";
                c = -1;
            } else {
                cout << "━";
            }
            ++c;
        }
        cout << endl;
    }
};

// Sudoku Solver Function
bool is_safe(int x, int y, int num, int grid[9][9])
{
    for (int i = 0; i < 9; i++) {
        if (grid[x][i] == num || grid[i][y] == num) {
            return false;
        }
    }
    int startRow = x - x % 3, startCol = y - y % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int grid[9][9])
{
    int row, col;
    bool empty = false;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                empty = true;
                break;
            }
        }
        if (empty) break;
    }
    if (!empty) return true;
    for (int num = 1; num <= 9; num++) {
        if (is_safe(row, col, num, grid)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

void printGrid(int grid[9][9])
{
    for (int r = 0; r < 9; r++) {
        for (int d = 0; d < 9; d++) {
            cout << grid[r][d] << " ";
        }
        cout << endl;
    }
}

// Main
int main()
{
    int N = 9;
    int K = 20;
    Sudoku* sudoku = new Sudoku(N, K);
    sudoku->fillValues();
    cout << "Generated Sudoku Puzzle:\n";
    sudoku->printSudoku();

    int grid[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j] = sudoku->mat[i][j];
        }
    }

    if (solveSudoku(grid)) {
        cout << "Solved Sudoku Puzzle:\n";
        // printGrid(grid);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                sudoku->mat[i][j] = grid[i][j];
            }
        }
        sudoku->printSudoku();
    } else {
        cout << "No solution exists.\n";
    }
    return 0;
}

// This code is contributed by Aarti_Rathi
// This code is contributed by ishankhandelwals.
// This code is modified by Susobhan Akhuli
// This code is modified by Brock Skelton