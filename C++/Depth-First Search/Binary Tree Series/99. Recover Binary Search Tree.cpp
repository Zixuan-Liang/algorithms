/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    // 中序遍历，得到一个几乎排好序的数组（有两个数字交换过）
    vector<int> inorder(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        res = inorder(root->left);
        res.push_back(root->val);
        vector<int> right = inorder(root->right);
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }
    
    // 从几乎排好序的数组中找出交换过的两个数
    pair<int, int> findTwoSwapped(vector<int>& nums) {
        int x = -1, y = -1;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] > nums[i+1] && x == -1) {
                x = i;
            }
            else if (nums[i] > nums[i+1]) {
                y = i+1;
            }
        }
        // 这里处理一下corner case, x和y相邻，nums[i] > nums[i+1]只出现了一次
        // 如果x和y不相邻，nums[i] > nums[i+1]在上面的循环会出现两次
        if (y == -1) y = x+1;
        return {nums[x], nums[y]};
    }
    
    // count 用来记录还差多少个数要修复，初始为2
    void recover(TreeNode* root, int count, int x, int y) {
        if (root) {
            if (root->val == x || root->val == y) {
                root->val = (root->val == x) ? y : x;
                count--;
                if (count == 0) return ;
            }
            recover(root->left, count, x, y);
            recover(root->right, count, x, y);
        }
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> nums = inorder(root);
        pair<int, int> swaps = findTwoSwapped(nums);
        int x = swaps.first, y = swaps.second;
        recover(root, 2, x, y);
    }
};