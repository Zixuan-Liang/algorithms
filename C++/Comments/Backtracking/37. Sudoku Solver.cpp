// Complexity: (9!)^9

class Solution {
public:
    
    int n;
    int N;
    function<int(int, int)> boxIndex = [&](int row, int col)->int {return row / n * n + col / n;}; // lambda function to compute box index
    vector<unordered_set<int>> rows, columns, boxes;
    bool solved = false;
    
    // Check if one can place a number d in (row, col) cell
    bool canPlace(int row, int col, int d) {
        return !(rows[row].count(d) || columns[col].count(d) || boxes[boxIndex(row, col)].count(d));
    }
    
    // Place a number d in (row, col) cell
    void placeNumber(vector<vector<char>>& board, int row, int col, int d) {
        rows[row].insert(d);
        columns[col].insert(d);
        boxes[boxIndex(row, col)].insert(d);
        board[row][col] = '0' + d;
    }
    
    // Remove a number which didn't lead to a solution
    void removeNumber(vector<vector<char>>& board, int row, int col, int d) {
        rows[row].erase(d);
        columns[col].erase(d);
        boxes[boxIndex(row, col)].erase(d);
        board[row][col] = '.';
    }
    
    // Call backtrack to place remaining numbers
    void placeRemainingNumbers(vector<vector<char>>& board, int row, int col) {
        if (row == N - 1 && col == N - 1){
            solved = true;
        }
        else {
            if (col == N - 1) {
                backtrack(board, row + 1, 0);
            }
            else {
                backtrack(board, row, col + 1);
            }
        }
    }
    
    void backtrack(vector<vector<char>>& board, int row, int col) {
        if (board[row][col] == '.') {
            for (int d = 1; d <= 9; d++) {
                if (canPlace(row, col, d)) {
                    placeNumber(board, row, col, d);
                    placeRemainingNumbers(board, row, col);
                    if (!solved) {
                        removeNumber(board, row, col, d);
                    }
                }
            }
        }
        else {
            placeRemainingNumbers(board, row, col);
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        n = 3; // box size
        N = n * n; // row size
        rows.resize(N);
        columns.resize(N);
        boxes.resize(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] != '.') {
                    int d = board[i][j] - '0';
                    placeNumber(board, i, j, d);
                }
            }
        }
        backtrack(board, 0, 0);
    }
};