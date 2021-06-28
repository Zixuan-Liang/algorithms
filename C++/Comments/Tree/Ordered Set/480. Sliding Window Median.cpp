#include <set>

// 平衡树 Ordered Set (不用堆是因为Ordered Set方便删除移出滑动窗口外的元素)
// 复杂度：窗口大小k，数组大小n，时间O(nlogk)，空间O(k)
class Solution {
public:
        
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        bool odd = k % 2 == 1; // 根据k是否为偶数，中位数计算稍微不同
        multiset<int> lower, upper; // 建立两个ordered set，A：最小的k/2个数，B：最大的k/2个数
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) { // 需要将滑动窗口外的元素移出集合
                if (nums[i - k] <= *lower.rbegin())
                    lower.erase(lower.find(nums[i-k])); // 注意不要用erase(数值)，这样会删除所有重复的，要用erase(指针)
                else
                    upper.erase(upper.find(nums[i-k]));
            }
            lower.insert(nums[i]); // 添加新元素，先加到A，然后把A的最大值转移到B
            upper.insert(*lower.rbegin());
            lower.erase(prev(lower.end()));
            if (lower.size() < upper.size()) { // 保证A的元素个数大于等于B
                lower.insert(*upper.begin());
                upper.erase(upper.begin());
            }
            if (i >= k - 1) { // 从第k个数开始要计算中位数
                if (odd) { // k为计数
                    ans.push_back(*lower.rbegin());
                }
                else { // k为偶数
                    ans.push_back((1.0 * *lower.rbegin() + 1.0 * *upper.begin()) / 2);
                }
            }
        }
        return ans;
    }
};