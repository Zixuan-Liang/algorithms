// 单调队列实现常数时间（amortized）求取滑动窗口最大值
// 保证队列头就是窗口的最大值
// 复杂度：时间：O(n)，空间：O(k)

// 如果使用优先队列(multiset以方便出队)，复杂度为(nlogk)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() <= i - k) { // 如果队列头不在窗口内，队头出队
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) { // 如果队列尾比当前数值小，队尾出队，保证队列单调，队头永远是最大值
                dq.pop_back();
            }
            dq.push_back(i); // 当前数值进队
            if (i >= k - 1) ans.push_back(nums[dq.front()]); // 从第k个数开始，每访问一个数就获得一个滑动窗口最大值
        }
        return ans;
    }
};