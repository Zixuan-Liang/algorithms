class Solution {
public:
    
    unordered_set<int> mainDiag, minorDiag, cols;

    void backtrack(int row, vector<string>& board, int n, vector<vector<string>>& res) {
        if (row == n) {
            res.push_back(board); 
            return ;
        }
        for (int col = 0; col < n; col++) {
            int currMainDiag = row - col; // 主对角线
            int currMinorDiag = row + col; // 副对角线
            if (cols.count(col) || mainDiag.count(currMainDiag) || minorDiag.count(currMinorDiag)) { // 当前位置放置不了
                continue;
            }
            cols.insert(col); // 放置当前位置
            mainDiag.insert(currMainDiag);
            minorDiag.insert(currMinorDiag);
            board[row][col] = 'Q';
            backtrack(row+1, board, n, res); // 回溯
            cols.erase(col); // 撤销放置当前位置
            mainDiag.erase(currMainDiag);
            minorDiag.erase(currMinorDiag);
            board[row][col] = '.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));     
        
        backtrack(0, board, n, res);
        
        return res;
    }
};