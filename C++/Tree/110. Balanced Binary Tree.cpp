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
    
    pair<bool, int> helper(TreeNode* root) {
        if (!root) return {true, 0};
        auto left = helper(root->left), right = helper(root->right);
        bool leftB = get<0>(left), rightB = get<0>(right);
        int leftH = get<1>(left), rightH = get<1>(right);
        bool b = leftB && rightB && abs(leftH-rightH) <= 1;
        int h = max(leftH, rightH) + 1;
        return {b, h};
    }
    
    bool isBalanced(TreeNode* root) {
        return get<0>(helper(root));
    }
};