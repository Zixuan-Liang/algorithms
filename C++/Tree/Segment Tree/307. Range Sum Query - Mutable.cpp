class NumArray {
    
    int n;
    vector<int> tree;
    
public:
    
    void buildTree(vector<int>& nums) {
        for (int i = n, j = 0; i < 2 * n; i++, j++) {
            tree[i] = nums[j];
        }
        for (int i = n - 1; i > 0; i--) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree = vector<int>(2*n, 0);
        buildTree(nums);
    }
    
    void update(int index, int val) {
        index += n;
        tree[index] = val;
        while (index > 1) {
            index = index / 2;
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
        }
    }
    
    int sumRange(int left, int right) {
        int ans = 0;
        left += n;
        right += n;
        while (left <= right) {
            if (left % 2 == 1) {
                ans += tree[left];
                left++;
            }
            left = left / 2;
            if (right % 2 == 0) {
                ans += tree[right];
                right--;
            }
            right = right / 2;
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */