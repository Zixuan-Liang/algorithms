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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            res.push_back(stk.top()->val);
            root = stk.top()->right;
            stk.pop();
        }
        return res;
    }
};

// 递归

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if (!root) return res;
//         res = inorderTraversal(root->left);
//         res.push_back(root->val);
//         vector<int> right = inorderTraversal(root->right);
//         res.insert(res.end(), right.begin(), right.end());
//         return res;
//     }
// };