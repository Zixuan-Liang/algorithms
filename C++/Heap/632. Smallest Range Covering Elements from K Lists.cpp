// 从 k 个列表中各取一个数，使得这 k 个数中的最大值与最小值的差最小。
// 使用最小堆维护 k 个指针指向的元素中的最小值，同时维护堆中元素的最大值。
// 其实就是merge k sorted lists

class Solution {
    typedef pair<int, pair<int, int>> PII;
public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        int n = nums.size();
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        int currMax = -1e7, start = -1e7, end = 1e7;
        for (int i = 0; i < n; ++i) {
            pq.push(make_pair(nums[i][0], make_pair(i, 0)));
            currMax = max(currMax, nums[i][0]);
        }
        while (pq.size() == n) {
            PII a = pq.top();
            pq.pop();
            int val = a.first, i = a.second.first, j = a.second.second;
            if (currMax - val < end - start) start = val, end = currMax;
            if (j + 1 < nums[i].size()) {
                pq.push(make_pair(nums[i][j + 1], make_pair(i, j + 1))); 
                currMax = max(currMax, nums[i][j+1]);
            } 
        }
        return {start, end};
    }
};