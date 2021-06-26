class Solution {
public:
    
    double timeToFinish(vector<int>& dist, int speed) {
        double time = 0;
        for (int i = 0; i < dist.size() - 1; i++) {
            time += (dist[i] - 1) / speed + 1;
        }
        time += 1.0 * dist.back() / speed;
        return time;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour - (n - 1) <= 0) return -1;
        int low = 1, high = max(100000, (int)ceil(dist.back()/(hour - (n-1))));
        while (low < high) {
            int mid = low + (high - low) / 2;
            double time = timeToFinish(dist, mid);
            if (time > hour) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
};