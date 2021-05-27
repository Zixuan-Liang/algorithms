class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> lastSeen;
        for (int i = 0; i < s.size(); i++) lastSeen[s[i]] = i;
        
        deque<char> stk;
        unordered_set<char> used;
        for (int i = 0; i < s.size(); i++) {
            
            char c = s[i];
            
            if (used.find(c) == used.end()) {
                
                while (!stk.empty() && stk.back() >= c && lastSeen[stk.back()] > i) {
                    used.erase(stk.back());
                    stk.pop_back();
                }
                
                used.insert(c);
                stk.push_back(c);
            }
        }
        
        string res;
        while (!stk.empty()) {
            res += stk.front();
            stk.pop_front();
        }
        
        return res;
    }
};