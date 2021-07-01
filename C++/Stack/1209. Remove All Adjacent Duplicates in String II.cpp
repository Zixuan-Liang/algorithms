class Solution {
public:
    string removeDuplicates(string s, int k) {
        deque<pair<char, int>> dq; // {letter, count}
        for (char c : s) {
            if (!dq.empty() && c == dq.back().first) {
                if (dq.back().second >= k-1) {
                    dq.pop_back();
                }
                else {
                    dq.back().second++;
                }
            }
            else {
                dq.push_back({c, 1});
            }
        }
        string ans = "";
        while (!dq.empty()) {
            for (int i = 0; i < dq.front().second; i++) {
                ans += dq.front().first;
            }
            dq.pop_front();
        }
        return ans;
    }
};