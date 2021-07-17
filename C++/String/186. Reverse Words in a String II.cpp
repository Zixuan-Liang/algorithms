class Solution {
public:
    
    void helper(vector<char>& s, int left, int right) {
        while(left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    
    void reverseWords(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        int prevSpace = -1;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                helper(s, prevSpace + 1, i - 1);
                prevSpace = i;
            }
            i++;
        }
        helper(s, prevSpace + 1, s.size() - 1);
    }
};