struct VectorHash {
    std::size_t operator()(const vector<int>& vec) const {
          std::size_t seed = vec.size();
          for(auto& i : vec) {
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
          }
          return seed;
    }
};

class Solution {
public:
    
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& comb, int start) {
        res.push_back(comb);
        for (int i = start; i < nums.size(); i++) {
            comb.push_back(nums[i]);
            backtrack(nums, res, comb, i+1);
            comb.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> comb;
        sort(begin(nums), end(nums));
        backtrack(nums, res, comb, 0);
        
        unordered_set<vector<int>, VectorHash> s( res.begin(), res.end() );
        res.assign( s.begin(), s.end() );
        
        return res;
    }
};