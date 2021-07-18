class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans(num1.size()+num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; j--) {
                int prod = ans[i+j+1] + (num1[i] - '0') * (num2[j] - '0') + carry;
                ans[i+j+1] = prod % 10;
                carry = prod / 10;
            }
            ans[i] += carry;
        }
        int pos = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (i == ans.size() - 1 && ans[i] == 0) {
                return "0";
            }
            else if (ans[i] == 0) {
                pos++;
            }
            else {
                break;
            }
        }
        string res = "";
        for (int i = pos; i < ans.size(); i++) {
            res += to_string(ans[i]);
        }
        return res;
    }
};