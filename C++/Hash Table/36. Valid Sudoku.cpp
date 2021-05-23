class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9], col[9], box[9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    if (row[i].find(c) != row[i].end()) return false;
                    row[i].insert(c);
                    if (col[j].find(c) != col[j].end()) return false;
                    col[j].insert(c);
                    int idx = (i/3)*3+j/3;
                    if (box[idx].find(c) != box[idx].end()) return false;
                    box[idx].insert(c);
                }
            }
        }
        return true;
    }
};