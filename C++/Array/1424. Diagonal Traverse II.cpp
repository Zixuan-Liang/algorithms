class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> store; 
        vector<int> res; 
        
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums[i].size(); j++)
                if (store.size() <= i + j)
                    store.push_back({nums[i][j]});
                else
                    store[i + j].push_back(nums[i][j]);
        
        for (int i = 0; i < store.size(); i++)
            for (int j = store[i].size() - 1; j >= 0; j--)
                res.push_back(store[i][j]);
        
        return res; 
    }
};