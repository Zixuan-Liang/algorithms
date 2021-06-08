class Solution {
public:
    
    double find_min_Rec(vector<pair<int,int>> & xy0, int dx, int dy){
        int n = xy0.size();
        if(n<2) return -1;
        double tmp_area, min_area = -1;
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++){
                int dx1 = xy0[i].first  - xy0[j].first;
                int dy1 = xy0[i].second - xy0[j].second;
                if(dx1==0 && dy1==0) continue;
                if(dx*dx1+dy*dy1==0){
                    // 向量(a,b), (c,d)叉乘就是它们组成的平行四边形的面积 area = (ad - bc)
                    tmp_area = abs((double)dx*(double)dy1 - (double)dy*(double)dx1);
                    if(min_area<0) min_area = tmp_area;
                    else min_area = min(min_area, tmp_area);
                }
            }
        return min_area;
    }
    
    double minAreaFreeRect(vector<vector<int>>& points) {
        map<pair<int,int>, vector<pair<int,int>>> lines; //(dx,dy)->(x0,y0)
        int n = points.size();
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++){
                if(points[i][0]>points[j][0]){
                    int dx = points[i][0]-points[j][0];
                    int dy = points[i][1]-points[j][1];
                    int x0 = points[j][0], y0 = points[j][1];
                    if(dy>=0) lines[{dx,dy}].push_back({x0,y0});
                } else {
                    int dx = points[j][0]-points[i][0];
                    int dy = points[j][1]-points[i][1];
                    int x0 = points[i][0], y0 = points[i][1];
                    if(dy>=0) lines[{dx,dy}].push_back({x0,y0}); 
                }
            }
        double minArea = -1;
        
        for(auto it = lines.begin();it!=lines.end();it++){
            double tmp_min_area = find_min_Rec(it->second, it->first.first, it->first.second);
            if(tmp_min_area<0) continue;
            if(minArea<0) minArea = tmp_min_area;
            else minArea = min(tmp_min_area,minArea);
        }
        
        return minArea<0?0:minArea;
            
    }
};