class Solution {
public:
    
    static bool sortByPos(pair<int, int>& x, pair<int, int>& y) {
        return x.second > y.second;
    }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> speedPos;
        for (int i = 0; i < position.size(); i++) {
            speedPos.push_back({speed[i], position[i]});
        }
        sort(speedPos.begin(), speedPos.end(), sortByPos);
        vector<double> timeToDest;
        for (auto& s : speedPos) {
            timeToDest.push_back( (target - s.second) / (double)s.first );
        }
        int fleet = 0;
        int index = 0;
        double prevTime = -1;
        while (index < timeToDest.size() && timeToDest[index] > prevTime) {
            fleet++;
            prevTime = timeToDest[index];
            while (index < timeToDest.size() && timeToDest[index] <= prevTime) {
                index++;
            }
        }
        return fleet;
    }
};