class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& b1, const vector<int>& b2)->bool{
            return b1[1] > b2[1];
        });
        int ans = 0;
        int index = 0;
        while (truckSize > 0 && index < boxTypes.size()) {
            int boxes = boxTypes[index][0];
            int units = boxTypes[index][1];
            ans += units * min(truckSize, boxes);
            truckSize -= boxes;
            index++;
        }
        return ans;
    }
};