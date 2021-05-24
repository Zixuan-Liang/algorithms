class Solution {
public:
    
    void backtrack(int row, set<int>& mainDiag, set<int>& minorDiag, set<int>& cols, vector<string>& board, int n, vector<vector<string>>& res) {
        if (row == n) {res.push_back(board); return ;}
        for (int col = 0; col < n; col++) {
            int currMainDiag = row - col;
            int currMinorDiag = row + col;
            if (cols.find(col)!=cols.end() || mainDiag.find(currMainDiag)!=mainDiag.end() || minorDiag.find(currMinorDiag)!=minorDiag.end()) continue;
            cols.insert(col);
            mainDiag.insert(currMainDiag);
            minorDiag.insert(currMinorDiag);
            board[row][col] = 'Q';
            backtrack(row+1, mainDiag, minorDiag, cols, board, n, res);
            cols.erase(col);
            mainDiag.erase(currMainDiag);
            minorDiag.erase(currMinorDiag);
            board[row][col] = '.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        set<int> mainDiag, minorDiag, cols;        
        
        backtrack(0, mainDiag, minorDiag, cols, board, n, res);
        
        return res;
    }
};