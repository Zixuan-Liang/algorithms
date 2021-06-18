class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int m = s1.size(), n = s2.size();
        if (m > n) return false;
        
        unordered_map<char, int> count1;
        for (char c : s1) count1[c]++;
        
        unordered_map<char, int> count2;
        for (int i = 0; i < m; i++) {
            count2[s2[i]]++;
        }
        if (count1 == count2) return true;
        
        for (int i = m; i < n; i++) {
            count2[s2[i]]++;
            count2[s2[i-m]]--;
            if (count2[s2[i-m]] == 0) count2.erase(s2[i-m]);
            if (count1 == count2) return true;
        }
        
        return false;
    }
};