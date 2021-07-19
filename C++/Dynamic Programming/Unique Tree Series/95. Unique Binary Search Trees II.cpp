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
    
    vector<TreeNode*> helper(int start, int end, map<pair<int, int>, vector<TreeNode*>>& memo) {
        if (memo.find({start, end}) == memo.end()) {
            vector<TreeNode*> res;
            if (start > end) {
                res.push_back(nullptr);
            }
            else {
                for (int i = start; i <= end; i++) {
                    for (auto& left : helper(start, i-1, memo)) {
                        for (auto& right : helper(i+1, end, memo)) {
                            TreeNode* root = new TreeNode(i, left, right);                            
                            res.push_back(root);
                        }
                    }
                }
            }
            memo[{start, end}] = res;
        }
        return memo[{start, end}];
    }
    
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> memo;
        return helper(1, n, memo);
    }
};