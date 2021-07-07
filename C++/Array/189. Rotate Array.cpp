// O(n) time O(n) space, naive
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> temp(nums.end()-k, nums.end());
        for (int i = n-1; i >= k ; i--) {
            nums[i] = nums[i-k];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};


// O(n) time O(1) space, find gcd and rotate by groups

#include <numeric>
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = gcd(k, n);
        for (int start = 0; start < count; ++start) {
            int current = start;
            do {
                int next = (current + k) % n;
                swap(nums[next], nums[start]);
                current = next;
            } while (start != current);
        }
    }
};

// O(n) time (1) space, using reverse
class Solution {
public:

    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k % n;
        if (k == 0) return ;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        
    }
};