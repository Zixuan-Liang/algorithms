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
    
    tuple<bool, long, long> helper(TreeNode* root) {
        if (!root) return tuple{true, long(INT_MIN) * 2 , long(INT_MAX) * 2};
        else {
            auto left = helper(root->left);
            auto right = helper(root->right);
            bool rootCheck = get<0>(left) && get<0>(right) && root->val > get<1>(left) && root->val < get<2>(right);
            long maxVal = max({(long)root->val, get<1>(left), get<1>(right)});
            long minVal = min({(long)root->val, get<2>(left), get<2>(right)});
            return tuple{rootCheck, maxVal, minVal};
        }
    }
    
    bool isValidBST(TreeNode* root) {
        return get<0>(helper(root));
    }
};