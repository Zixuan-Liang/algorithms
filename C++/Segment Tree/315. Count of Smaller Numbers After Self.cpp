class Solution {
    
    int offset = 10000;
    int n = 20001;
    vector<int> tree;
    
public:
    
    void updateTree(int node, int left, int right, int index) {
        if (left == right) {
            tree[node]++;
        }
        else {
            int mid = left + (right - left) / 2;
            if (index <= mid) {
                updateTree(node * 2, left, mid, index);
            }
            else {
                updateTree(node * 2 + 1, mid + 1, right, index);
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
    
    vector<int> countSmaller(vector<int>& nums) {
        tree.resize(4 * n, 0);
        vector<int> ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            int num = nums[i] + offset;
            ans[i] = queryTree(1, 0, 20000, 0, num - 1);
            updateTree(1, 0, 20000, num);
        }
        return ans;
    }
};