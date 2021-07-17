#include <vector>

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size(), mid, left, right;
        while (start < end) {
            mid = (start + end) / 2;
            if (nums[mid] >= target)
                end = mid;
            else
                start = mid + 1;
        }
        left = start;
        start = 0, end = nums.size();
        while (start < end) {
            mid = (start + end) / 2;
            if (nums[mid] > target)
                end = mid;
            else
                start = mid + 1;
        }
        right = start;
        return left == right ? vector<int> {-1,-1} : vector<int> {left,right-1};
    }
};

// Using the <algorithm> methods lower_bound and upper_bound
// lower_bound返回第一个大于等于target的迭代器
// upper_bound返回第一个大于target的迭代器
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start;
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        if (lb != nums.end() && *lb == target) {
            start = lb - nums.begin();
        }
        else {
            start = -1;
        }
        int end;
        auto ub = upper_bound(nums.begin(), nums.end(), target);
        if (ub != nums.begin() && *(ub-1) == target) {
            end = ub - 1 - nums.begin();
        }
        else {
            end = -1;
        }
        return {start, end};
    }
};