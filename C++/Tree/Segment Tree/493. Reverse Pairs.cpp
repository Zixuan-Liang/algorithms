struct SegmentTree {
    
    SegmentTree* left;
    SegmentTree* right;
    int count;
    long min;
    long max;
    
    // nums is sorted
    SegmentTree(vector<int>& nums, int l, int r): left(nullptr), right(nullptr) {
        min = nums[l];
        max = nums[r];
        count = 0;
        if (l == r) return;
        int m = l + (r - l) / 2;
        if (l <= m) {
            left = new SegmentTree(nums, l, m);
        }
        if (m + 1 <= r) {
            right = new SegmentTree(nums, m + 1, r);
        }
    }
    
    void updateTree(int value) {
        if (value < min or value > max) {
            return ;
        }
        if (left and left->min <= value and value <= left->max) {
            left->updateTree(value);
        }
        else if (right and right->min <= value and value <= right->max) {
            right->updateTree(value);
        }
        count++;
    }
    
    int queryTree(long minValue, long maxValue) {
        if (minValue<=min && max<=maxValue) {
            return count;
        }
        else if (maxValue<min || minValue>max) {
            return 0;
        }
        else {
            int q1 = left ? left->queryTree(minValue, maxValue) : 0;
            int q2 = right ? right->queryTree(minValue, maxValue) : 0;
            return q1 + q2;
        }
    }
};

class Solution {
public:
    
    int reversePairs(vector<int>& nums) {
        
        unordered_set<int> uset;
        for (int n : nums) uset.insert(n);
        vector<int> v(uset.begin(), uset.end());
        sort(v.begin(), v.end());
        
        SegmentTree* tree = new SegmentTree(v, 0, v.size() - 1);
        
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += tree->queryTree(2 * (long)nums[i] + 1, (long)v.back());
            tree->updateTree(nums[i]);
        }
        return ans;
    }

};