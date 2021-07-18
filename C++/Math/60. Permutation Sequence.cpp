class Solution {
public:
    
    string getPermutation(int n, int k) {
        string a = "";
        for (int i = 1; i <= n; i++) // 以n=9为例a初始化为“123456789”
            a += to_string(i);
        vector<int> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) // 计算1到n的阶乘
            fact[i] = fact[i - 1] * i;
        k--;
        string ans = "";
        for (int i = n - 1; i >= 0; i--) { // 当前数字后面的数字个数：从n-1到0
            int index = k / fact[i]; // 后面有i个数字，组合为i!，当前k对i!的倍数决定当前数字
            k %= fact[i]; // 更新k为k对i!的余数
            ans += a[index];
            a.erase(a.begin() + index); // a删除对应数字
        }
        return ans;
    }
    
};