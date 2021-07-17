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
#include <queue>

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> nodes;
        if (root) nodes.push(root);
        int res, level = 0, maxSum = INT_MIN;
        while (!nodes.empty()) {
            level++;
            int len = nodes.size();
            int sum = 0;
            for (int i = 0; i < len; i++) {
                TreeNode* top = nodes.front();
                sum += top->val;
                if (top->left) nodes.push(top->left);
                if (top->right) nodes.push(top->right);
                nodes.pop();
            }
            if (sum > maxSum) {
                res = level;
                maxSum = sum;
            }
        }
        return res;
    }
};