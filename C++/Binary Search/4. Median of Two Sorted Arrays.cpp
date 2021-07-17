#include <algorithm>
#include <vector>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength+1)/2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength/2) + getKthElement(nums1, nums2, totalLength/2+1)) / 2;
        }
    }
    
    double getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int index1 = 0, index2 = 0;
        int m = nums1.size(), n = nums2.size();
        int newIndex1, newIndex2;
        while (true) {
            // 特殊情况
            if (index1 == m) {
                return (double)nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return (double)nums1[index1 + k - 1];
            }
            if (k == 1) {
                return (double)min(nums1[index1], nums2[index2]);
            }
            // 一般情况
            newIndex1 = min(index1 + k/2-1, m-1);
            newIndex2 = min(index2 + k/2-1, n-1);
            if (nums1[newIndex1] <= nums2[newIndex2]) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }
};