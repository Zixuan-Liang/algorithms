class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
        
        unordered_map<int, int> count1;
        for (int n : nums1) count1[n]++;
        
        int k = 0;
        for (int n : nums2) {
            // if (count1.count(n) && --count1[n] >= 0) {
            //     nums1[k++] = n;
            // }
            auto it = count1.find(n);
            if (it != end(count1) && --it->second >= 0) {
                nums1[k++] = n;
            }
        }
        return vector(begin(nums1), begin(nums1) + k);
    }
};

// If arrays are already sorted: linear scan and constant space
// vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//     int i = 0, j = 0, k = 0;
//     while (i < nums1.size() && j < nums2.size()) {
//         if (nums1[i] < nums2[j]) {
//             ++i;
//         } else if (nums1[i] > nums2[j]) {
//             ++j;
//         } else {
//             nums1[k++] = nums1[i++];
//             ++j;
//         }
//     }
//     return vector<int>(begin(nums1), begin(nums1) + k);
// }

// If nums1's size is small compared to nums2's size?
// Using hash is better.

// What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
// If nums1 fits into the memory, we can use Approach 1 to collect counts for nums1 into a hash map. Then, we can sequentially load and process nums2.
// If neither of the arrays fit into the memory, we can apply some partial processing strategies:
// Split the numeric range into subranges that fits into the memory. Modify Approach 1 to collect counts only within a given subrange, and call the method multiple times (for each subrange).
// Use an external sort for both arrays. Modify Approach 2 to load and process arrays sequentially.