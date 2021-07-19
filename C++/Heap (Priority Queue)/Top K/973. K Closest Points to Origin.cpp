#include <queue>

struct comparePoints {
    
    static int distance(vector<int>& p) {
        return p[0] * p[0] + p[1] * p[1];
    }
    
    bool operator()(vector<int>& p1, vector<int>& p2) {
        return distance(p1) < distance(p2);
    }  
};

class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, comparePoints> maxHeap;
        for (auto& p : points) {
            maxHeap.push(p);
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return res;
    }
};