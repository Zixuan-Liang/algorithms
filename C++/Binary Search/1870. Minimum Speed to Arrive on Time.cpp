class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (hour - (dist.size() - 1) <= 0) return -1;
        int left = 1, right = pow(10, 9);
        while (left < right) {
            int pivot = (left + right) / 2;
            double time = 0;
            for (int i = 0; i < dist.size() - 1; i++) {
                time += (dist[i] - 1) / pivot + 1;
            }
            time += 1.0 * dist.back() / pivot;
            if (time > hour) {
                left = pivot + 1;
            }
            else {
                right = pivot;
            }
        }
        return right;
    }
};