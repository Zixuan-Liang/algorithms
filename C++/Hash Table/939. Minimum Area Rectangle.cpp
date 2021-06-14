class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int res = INT_MAX;
        unordered_map<int, unordered_set<int>> myMap;
        for (auto point : points) {
            myMap[point[0]].insert(point[1]);
        }
        for(int i=0; i<points.size(); i++){
            for( int j = i+1; j<points.size(); j++){
                int p1x = points[i][0], p1y = points[i][1];
                int p2x = points[j][0], p2y = points[j][1];
                if(p1x != p2x && p1y != p2y && myMap[p1x].find(p2y) != myMap[p1x].end() && myMap[p2x].find(p1y) != myMap[p2x].end()){
                        res = min(res, (abs((p2x-p1x)*(p2y-p1y))));                 
                }
            }
        }
        return (res == INT_MAX) ? 0 : res;
        
    }
};