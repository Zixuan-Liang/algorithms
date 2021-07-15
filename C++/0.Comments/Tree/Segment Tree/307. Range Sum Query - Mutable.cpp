class NumArray {
    
    int n;
    vector<int> tree;
    
public:
    
    void buildTree(vector<int>& nums, int node, int left, int right) {
        if (left == right) {
            tree[node] = nums[left];
        }
        else {
            int mid = left + (right - left) / 2;
            buildTree(nums, node * 2, left, mid);
            buildTree(nums, node * 2 + 1, mid + 1, right);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }
    
    void updateTree(int node, int left, int right, int index, int val) {
        if (left == right) {
            tree[node] = val;
        }
        else {
            int mid = left + (right - left) / 2;
            if (index <= mid) {
                updateTree(node * 2, left, mid, index, val);
            }
            else {
                updateTree(node * 2 + 1, mid + 1, right, index, val);
            }
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }
    
    int queryTree(int node, int left, int right, int queryLeft, int queryRight) {
        if (queryRight < left or right < queryLeft) {
            return 0;
        }
        else if (queryLeft <= left and right <= queryRight) {
            return tree[node];
        }
        else {
            int mid = left + (right - left) / 2;
            int q1 = queryTree(node * 2, left, mid, queryLeft, queryRight);
            int q2 = queryTree(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
            return q1 + q2;
        }
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree = vector<int>(4*n, 0);
        buildTree(nums, 1, 0, n-1);
    }
    
    void update(int index, int val) {
        updateTree(1, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return queryTree(1, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */