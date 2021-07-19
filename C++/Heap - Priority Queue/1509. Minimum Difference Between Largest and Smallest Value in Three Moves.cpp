#include <queue>
#include <stack>

class Solution {
public:
    int minDifference(vector<int>& nums) {
        priority_queue<int> maxHeap, minHeap;
        int k = 4;
        for (int n : nums) {
            maxHeap.push(n);
            minHeap.push(-n);
            if (maxHeap.size() > k) maxHeap.pop();
            if (minHeap.size() > k) minHeap.pop();
        }
        int res = INT_MAX;
        stack<int> stk;
        while (!minHeap.empty()) {
            stk.push(-minHeap.top());
            minHeap.pop();
        }
        while (!stk.empty()) {
            res = min(res, stk.top() - maxHeap.top());
            maxHeap.pop();
            stk.pop();
        }
        return res;
    }
};