class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i = num1.size() - 1, j = num2.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry != 0) {
            char c1 = i>=0 ? num1[i] : '0';
            char c2 = j>=0 ? num2[j] : '0';
            int sum = (c1 - '0') + (c2 - '0') + carry;
            int digit = sum % 10;
            carry = sum / 10;
            ans += to_string(digit);
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};