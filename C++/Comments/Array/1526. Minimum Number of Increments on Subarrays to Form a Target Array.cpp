class Solution {
public:
    int minNumberOperations(vector<int>& A) {
        int res = 0, pre = 0;
        for (int a: A) {
            res += max(a - pre, 0); // 当前数值比前一个数超出x就需要添加x次递增
            pre = a;
        }
        return res;
    }
};