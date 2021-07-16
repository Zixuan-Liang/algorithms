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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            vector<int> level;
            int count = que.size();
            for (int i = 0; i < count; i++) {
                level.push_back(que.front()->val);
                if (que.front()->left) que.push(que.front()->left);
                if (que.front()->right) que.push(que.front()->right);
                que.pop();
            }
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};