struct SegmentTree {
    SegmentTree* left;
    SegmentTree* right;
    int count;
    long min;
    long max;
    
    // nums is sorted
    SegmentTree(vector<long>& nums, int l, int r): left(nullptr), right(nullptr) {
        min = nums[l];
        max = nums[r];
        count = 0;
        if (l == r) return;
        int m = l + (r - l)/2;
        if (l <= m) {
            left = new SegmentTree(nums, l,m);
        }
        if (m + 1 <= r) {
            right = new SegmentTree(nums, m+1, r);
        }
    }
    
    void updateTree(long value) {
        if (value<min || value>max) {
            return;
        }
        if (left && value<=left->max) {
            left->updateTree(value);
        } 
        else if (right && value>=right->min) {
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
    int countRangeSum(vector<int>& nums, int lower, int upper) {

        unordered_set<long> values;
        long sum = 0;
        for(int i=0;i<nums.size();++i) {
            sum += nums[i];
            values.insert(sum);
        }

        vector<long> sums;
        for(auto& v : values) {
            sums.push_back(v);
        }
        
        // 将所有的前缀和排序
        sort(sums.begin(), sums.end());
        
        // 根据拍好序的前缀和建立线段树
        SegmentTree* tree = new SegmentTree(sums, 0, sums.size()-1);

        int count = 0;
        for(int i = nums.size() - 1; i >= 0; i--) {
            // 前缀和从后到前更新线段树
            tree->updateTree(sum);
            // 下一个前缀和
            sum -= nums[i];
            // lower <= sum[i] - sum[j] <= upper
            // 查找[lower+前缀和, upper+前缀和]区间的数量
            count += tree->queryTree(lower + sum, upper + sum);
        }
        
        return count;
        
    }
};