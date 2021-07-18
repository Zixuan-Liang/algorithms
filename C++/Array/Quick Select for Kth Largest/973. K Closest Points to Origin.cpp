// struct Point {
    
//     int x;
//     int y;
    
//     Point(int _x, int _y) {
//         x = _x;
//         y = _y;
//     }
    
//     d2o() {
//         return x * x + y * y;
//     }
    
//     bool operator()(Point other) {
//         return this->d2o() < other.d2o();
//     }  
    
// };

class Solution {
public:
    
    int d2o(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    
    int partition(vector<vector<int>>& points, int left, int right, int pivotIdx) {
        int pivot = d2o(points[pivotIdx]);
        swap(points[right], points[pivotIdx]);
        int storeIdx = left;
        for (int i = left; i < right; i++) {
            if (d2o(points[i]) < pivot) {
                swap(points[i], points[storeIdx]);
                storeIdx++;
            }
        }
        swap(points[right], points[storeIdx]);
        return storeIdx;
    }
    
    void quickSelect(vector<vector<int>>& points, int left, int right, int kSmallestIdx) {
        if (left == right) {
            return ;
        }
        int pivotIdx = left + rand() % (right - left + 1);
        pivotIdx = partition(points, left, right, pivotIdx);
        if (pivotIdx == kSmallestIdx) {
            return ;
        }
        else if (pivotIdx > kSmallestIdx) {
            quickSelect(points, left, pivotIdx - 1, kSmallestIdx);
        }
        else {
            quickSelect(points, pivotIdx + 1, right, kSmallestIdx);
        }
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSelect(points, 0, points.size() - 1, k - 1);
        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
};





















