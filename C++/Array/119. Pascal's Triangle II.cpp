class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        if (numRows == 0) return res.back();
        res.push_back({1, 1});
        if (numRows == 1) return res.back();
        for (int i = 3; i <= numRows+1; i++) {
            vector<int> row;
            row.push_back(1);
            for (int j = 0; j < i-2 ; j++) {
                row.push_back(res.back()[j] + res.back()[j+1]); 
            }
            row.push_back(1);
            res.push_back(row);
        }
        return res.back();
    }
};