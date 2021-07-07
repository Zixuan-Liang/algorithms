// 从 k 个列表中各取一个数，使得这 k 个数中的最大值与最小值的差最小。
// 使用最小堆维护 k 个指针指向的元素中的最小值，同时维护堆中元素的最大值。
// 其实就是merge k sorted lists

class Solution {
    typedef tuple<int, int, int> TIII; // 元素值，元素所属的第i个数组，元素处于数组的j位置
public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        int n = nums.size();
        priority_queue<TIII, vector<TIII>, greater<TIII>> pq;
        int currMax = -1e9, start = -1e9, end = 1e9;
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i][0], i, 0});
            currMax = max(currMax, nums[i][0]);
        }
        while (pq.size() == n) {
            TIII a = pq.top();
            pq.pop();
            int val = get<0>(a), i = get<1>(a), j = get<2>(a);
            if (currMax - val < end - start) start = val, end = currMax;
            if (j + 1 < nums[i].size()) {
                pq.push({nums[i][j + 1], i, j + 1}); 
                currMax = max(currMax, nums[i][j+1]);
            } 
        }
        return {start, end};
    }
};