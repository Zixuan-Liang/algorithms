class Solution {
public:
    
    vector<string> to19 = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> tens = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    
    vector<string> helper(int n) {
        if (n == 0) {
            return {};
        }
        if (n >= 1 && n < 20) {
            return {to19[n]};
        }
        if (n < 100) {
            vector<string> ans = {tens[n/10]};
            vector<string> remain = helper(n%10);
            ans.insert(ans.end(), remain.begin(), remain.end());
            return ans;
        }
        if (n < 1000) {
            vector<string> ans = {to19[n/100], "Hundred"};
            vector<string> remain = helper(n%100);
            ans.insert(ans.end(), remain.begin(), remain.end());
            return ans;
        }
        vector<pair<int, string>> powers{{1,"Thousand"},{2,"Million"},{3,"Billion"}};
        for (auto [power, word] : powers) { 
            if (n < pow(1000, power+1)) {
                vector<string> ans = helper(n/pow(1000, power));
                ans.push_back(word);
                vector<string> remain = helper(n%(int)pow(1000, power));
                ans.insert(ans.end(), remain.begin(), remain.end());
                return ans;
            }
        }
        return {};
    }
    
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        vector<string> words = helper(num);
        string ans = words[0];
        for (int i = 1; i < words.size(); i++) {
            ans += " " + words[i];
        }
        return ans;
    }
};

