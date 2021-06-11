class Solution {
    
    vector<int> digits = {0, 1, 8, 2, 5, 6, 9};
    int _n;
    
public:
    
    int rotate(int num) {
        int res = 0;
        int i = 0;
        while (num) {
            int digit = num % 10;
            if (digit == 2) digit = 5;
            else if (digit == 5) digit = 2;
            else if (digit == 6) digit = 9;
            else if (digit == 9) digit = 6;
            res += digit * pow(10, i);
            num /= 10;
            i++;
        }
        return res;
    }
    
    void backtrack(int& res, int num) {
        if (num > _n) {
            return ;
        }
        else {
            if (rotate(num) != num){
                cout << rotate(num) << endl;
                res++;
            }
        }
        for (int d : digits) {
            if (num == 0 && d == 0) continue;
            num = num * 10 + d;
            backtrack(res, num);
            num /= 10;
        }
    }
    
    int rotatedDigits(int n) {
        _n = n;
        int res = 0;
        int num = 0;
        backtrack(res, num);
        return res;
    }
};