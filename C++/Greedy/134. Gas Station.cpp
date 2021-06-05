class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minIndex = 0;
        int minTank = INT_MAX;
        int total = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            if (total < minTank) {
                minTank = total;
                minIndex = i;
            }
        }
        if (total < 0) return -1;
        return (minIndex+1)%gas.size();
    }
};