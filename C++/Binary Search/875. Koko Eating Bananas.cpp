class Solution {
public:
    
    int timeCost(vector<int>& piles, int speed) {
        int res = 0;
        for (int p : piles) res += (p - 1) / speed + 1;
        return res;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int K = 0;
        for (int p : piles) K = max(K, p);
        int lo = 1, hi = K;
        int mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            int time = timeCost(piles, mid);
            if (time > h) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        return lo;
    }
};