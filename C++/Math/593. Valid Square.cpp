class Solution {
public:
    
    int distance(vector<int>& point1, vector<int>& point2) {
        int dx = point1[0] - point2[0];
        int dy = point1[1] - point2[1];
        return dx * dx + dy * dy;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p = {p1, p2, p3, p4};
        sort(p.begin(), p.end(), [](const vector<int>& point1, const vector<int>& point2) -> bool {
            return point1[0] < point2[0] || (point1[0] == point2[0] && point1[1] < point2[1]);
        });
        int d1 = distance(p[0], p[1]);
        int d2 = distance(p[1], p[3]);
        int d3 = distance(p[3], p[2]);
        int d4 = distance(p[2], p[0]);
        bool sameSides = (d1==d2 && d2==d3 && d3==d4 && d1!=0);
        int d5 = distance(p[0], p[3]);
        int d6 = distance(p[1], p[2]);
        bool sameDiags = (d5 == d6);
        return sameSides && sameDiags;
    }
};