class Solution {
public:
    int numSplits(string& s) {
        unordered_map<char, int> count1, count2;
        int res = 0;
        for (char c : s) {
            count2[c]++;
        }
        for (char c : s) {
            count1[c]++;
            count2[c]--;
            if (count2[c] == 0) count2.erase(c);
            if (count1.size() == count2.size()) {
                res++;
            }
        }
        return res;
    }
};