class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z > x + y) return false;
        if (x == y) return z == x || z == x + y;
        return z % gcd(x, y) == 0;
    }
    
    int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x%y);
    }
};