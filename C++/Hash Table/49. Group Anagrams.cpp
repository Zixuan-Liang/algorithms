class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> memo;
        string key;
        for (string& s : strs) {
            key = s;
            sort(key.begin(), key.end());
            memo[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& ele : memo) {
            res.push_back(ele.second);
        }
        return res;
    }
};