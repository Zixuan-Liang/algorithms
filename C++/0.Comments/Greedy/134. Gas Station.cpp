// 假设我们此前发现，从加油站x出发，每经过一个加油站就加一次油（包括起始加油站），最后一个可以到达的加油站是y
// 能够得出结论: 从x, y之间的任何一个加油站出发，都无法到达加油站y的下一个加油站。
// 发现了这一个性质后，算法就很清楚了：我们首先检查第0个加油站，并试图判断能否环绕一周；如果不能，就从第一个无法到达的加油站开始继续检查。

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;
            while (cnt < n) {
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas) {
                    break;
                }
                cnt++;
            }
            if (cnt == n) {
                return i;
            } else {
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};