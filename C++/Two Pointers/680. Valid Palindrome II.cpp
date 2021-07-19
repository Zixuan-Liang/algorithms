class Solution {
public:
    bool validPalindrome(string s) {
        
        /*
            because we can delete one character by using either a left pointer or
            right pointer, we can seperate the problem into two cases:
        */
        // Case 1: delete character at left pointer only
        // define left and right pointers:
        int l = 0, r = s.size() - 1;
        bool deletion = false;
        bool left_Palindrome = true;
        while (l < r && l >= 0) {
            if (s[l] == s[r]){
                ++l;
                --r;
            } else if (!deletion && s[l+1] == s[r]){
                deletion = true;
                --r;
                l = l + 2;
            } else {
                left_Palindrome = false;
                break;
            }
        }
        
        if (left_Palindrome) {
            return left_Palindrome;
        }
        
        // Case 2: delete character at right pointer only
        // define left and right pointers:
        l = 0;
        r = s.size() - 1;
        deletion = false;
        bool right_Palindrome = true;
        while (l < r && l >= 0) {         
            if (s[l] == s[r]){
                ++l;
                --r;
            } else if (!deletion && s[l] == s[r-1]){
                deletion = true;
                ++l;
                r = r - 2;
            } else {
                right_Palindrome = false;
                break;
            }
        }

        return (left_Palindrome || right_Palindrome);
    }
};