class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0;
        int prevOne = -1;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                if (prevOne == -1) {
                    res = max(res, i);
                }
                else {
                    res = max(res, (i - prevOne) / 2);
                }
                prevOne = i;
            }
        }
        if (prevOne < seats.size()) {
            res = max(res, (int)seats.size() - 1 - prevOne);
        }
        return res;
    }
};