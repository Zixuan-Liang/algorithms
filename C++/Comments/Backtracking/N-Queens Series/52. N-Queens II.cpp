class Solution {
public:
    
    unordered_set<int> mainDiag, minorDiag, cols;

    void backtrack(int row, vector<string>& board, int n, int& res) {
        if (row == n) {
            res++; 
            return ;
        }
        for (int col = 0; col < n; col++) {
            int currMainDiag = row - col;
            int currMinorDiag = row + col;
            if (cols.count(col) || mainDiag.count(currMainDiag) || minorDiag.count(currMinorDiag)) { // 当前位置放置不了
                continue;
            }
            cols.insert(col);
            mainDiag.insert(currMainDiag);
            minorDiag.insert(currMinorDiag);
            board[row][col] = 'Q';
            backtrack(row+1, board, n, res);
            cols.erase(col);
            mainDiag.erase(currMainDiag);
            minorDiag.erase(currMinorDiag);
            board[row][col] = '.';
        }
    }
    
    int totalNQueens(int n) {
        
        int res = 0;
        vector<string> board(n, string(n, '.'));
        
        backtrack(0, board, n, res);
        
        return res;
    }
};