struct PairHash{
    std::size_t operator()(const pair<int, int>& p) const {
        auto h1 = std::hash<int>{}(p.first);
        auto h2 = std::hash<int>{}(p.second);
        return h1^h2;
    }
};

class Solution {
    
    unordered_map<pair<int, int>, int, PairHash> memo;
    
public:

    int attempt(vector<int>& arr1, vector<int>& arr2, int index, int beatThis) {
        pair<int, int> key = {index, beatThis};
        if (memo.count(key)) return memo[key];
        if (index == arr1.size()) {
            memo[key] = 0;
            return 0;
        }
        // Don't replace arr1[index]
        int res1;
        if (beatThis < arr1[index]) {
            res1 = attempt(arr1, arr2, index+1, arr1[index]);
        }
        else {
            res1 = 1e9;
        }
        auto upper = upper_bound(arr2.begin(), arr2.end(), beatThis);
        // Replace arr1[index]
        int res2;
        if (upper == arr2.end()) {
            res2 = 1e9;
        }
        else {
            int tmp = *upper;
            res2 = attempt(arr1, arr2, index+1, tmp);
        }
        int res = min(res1, res2+1);
        memo[key] = res;
        return res;
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int res = attempt(arr1, arr2, 0, INT_MIN);
        return (res == 1e9) ? -1 : res;
    }
    
};