class Solution {
public:
    
    double myPowPos(double x, int n) {
        if (n == 0) return 1;
        else {
            double res = myPowPos(x, n/2);
            res *= res;
            if (n % 2 == 1) res *= x;
            return res;
        }
    }
    
    double myPow(double x, int n) {
        int sign = (abs(n)%2==1 && x<0) ? -1 : 1;
        bool reverse = n<0;
        
        x = abs(x);
        
        double res;
        // Corner case: n = INT_MIN
        if (n == INT_MIN) {
            n = INT_MAX;
            res = x * myPowPos(x, n);
        }
        else {
            n = abs(n);
            res = myPowPos(x, n);
        }
        
        if (reverse) res = 1/res;
        res = res * sign;
        return res;
    }
};