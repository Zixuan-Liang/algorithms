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
    
    void backtrack(vector<int>& candidates, int remain, vector<int>& comb, int start, vector<vector<int>>& res) {
        if (remain == 0) {
            res.push_back(comb);
            return ;
        }
        else if (remain < 0) {
            return ;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            comb.push_back(candidates[i]);
            backtrack(candidates, remain - candidates[i], comb, i+1, res);
            comb.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, comb, 0, res);
        
        unordered_set<vector<int>, VectorHash> s( res.begin(), res.end() );
        res.assign( s.begin(), s.end() );
        
        return res;
    }
};