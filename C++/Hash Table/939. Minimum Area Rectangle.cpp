class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int res = INT_MAX;
        unordered_map<int, unordered_set<int>> points_map; // {x: y}
        for (auto point : points) {
            points_map[point[0]].insert(point[1]);
        }
        for(int i=0; i<points.size(); i++){
            for( int j = i+1; j<points.size(); j++){
                int p1x = points[i][0], p1y = points[i][1];
                int p2x = points[j][0], p2y = points[j][1];
                if(p1x != p2x && p1y != p2y && points_map[p1x].count(p2y) && points_map[p2x].count(p1y)){ // 由两点确定长方形另外两点
                        res = min(res, (abs((p2x-p1x)*(p2y-p1y))));                 
                }
            }
        }
        return (res == INT_MAX) ? 0 : res;
        
    }
};