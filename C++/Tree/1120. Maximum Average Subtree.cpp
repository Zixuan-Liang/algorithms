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
    
    vector<int> helper(TreeNode* node, double& max_time) {
        if (!node) {
            return {0, 0}; // number of employees, total months
        }
        int count = 1, total_time = node->val;
        vector<int> left = helper(node->left, max_time);
        vector<int> right = helper(node->right, max_time);
        count += left[0] + right[0];
        total_time += left[1] + right[1];
        double curr_time = 1.0 * total_time / count;
        max_time = max(max_time, curr_time);
        return {count, total_time};
    }
    
    double maximumAverageSubtree(TreeNode* root) {
        double ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};