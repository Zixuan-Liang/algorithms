class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<vector<int>> valCount(7, vector<int>(3, 0));
        for (int i = 0; i < tops.size(); i++) {
            if (tops[i] == bottoms[i]) {
                valCount[tops[i]][2]++; // 共有的
            }
            else {
                valCount[tops[i]][0]++; // top独有的
                valCount[bottoms[i]][1]++; // bottom独有的
            }
        }
        int res = INT_MAX;
        for (int i = 1; i <= 6; i++) {
            if (valCount[i][0] + valCount[i][1] + valCount[i][2] == tops.size()) { // 可翻转成功的
                res = min(res, min(valCount[i][0], valCount[i][1]));
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};