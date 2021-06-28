// 快速选择解决topK问题
// 复杂度：平均O(n)，最坏O(n^2)
// 平均情况下：f(n) = f(n/2) + O(n)，根据主定理，平均O(n)
#include <vector>
#include <algorithm> // swap
#include <cstdlib> // rand

class Solution {
public:
    
    // 以nums[pivotIdx]为界划分数组，数组左边大于pivot
    int partition(vector<int>& nums, int left, int right, int pivotIdx) {
        int pivot = nums[pivotIdx];
        swap(nums[pivotIdx], nums[right]); // 将pivot移至数组最右
        int storeIdx = left; // 找出pivot最后应该存放的位置
        for (int i = left; i < right; i++) { // 从左到右遍历
            if (nums[i] > pivot) {  // 如果当前数字小于pivot，将其移至左边
                swap(nums[i], nums[storeIdx]);
                storeIdx++; // 更新pivot最后应该存放的位置
            }
        }
        swap(nums[right], nums[storeIdx]); // 把pivot放到它所属的位置
        return storeIdx;
    }
    
    // 快速选择
    int quickSelect(vector<int>& nums, int left, int right, int kLargestIdx) {
        if (left == right) { // base case
            return nums[left];
        }
        int pivotIdx = left + rand() % (right - left + 1); // 随机选择一个pivot
        pivotIdx = partition(nums, left, right, pivotIdx); // 划分数组
        if (pivotIdx == kLargestIdx) { // 如果刚好划分到topK，直接返回
            return nums[pivotIdx];
        }
        else if (pivotIdx > kLargestIdx) { // 向左继续搜
            return quickSelect(nums, left, pivotIdx - 1, kLargestIdx);
        }
        else { // 向右继续搜
            return quickSelect(nums, pivotIdx + 1, right, kLargestIdx);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k - 1);
    }

};