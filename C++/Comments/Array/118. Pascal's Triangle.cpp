class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        if (numRows == 1) return res;
        res.push_back({1, 1});
        if (numRows == 2) return res;
        for (int i = 3; i <= numRows; i++) {
            vector<int> row;
            row.push_back(1);
            for (int j = 0; j < i-2 ; j++) {
                row.push_back(res.back()[j] + res.back()[j+1]); 
            }
            row.push_back(1);
            res.push_back(row);
        }
        return res;
    }
};