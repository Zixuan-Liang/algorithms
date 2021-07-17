#include <cstdlib>

class Solution {
    
    vector<int> origin;
    vector<int> shuf;
    
public:
    Solution(vector<int>& nums) {
        for (int n : nums) origin.push_back(n);
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        shuf = origin;
        for (int i = origin.size(); i > 0; i--) {
            int index = rand() % i;
            swap(shuf[index], shuf[i-1]);
        }
        return shuf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */