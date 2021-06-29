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
    
    unordered_map<int, vector<TreeNode*>> memo;
    
public:
    
    vector<TreeNode*> allPossibleFBT(int n) {
        if (memo.count(n)) return memo[n];
        vector<TreeNode*> res;
        if (n % 2 == 0) {
        }
        else if (n == 1) {
            TreeNode* node = new TreeNode(0);
            res.push_back(node);
        }
        else {
            for (int i = 1; i < n-1; i+=2) {
                vector<TreeNode*> left = allPossibleFBT(i);
                vector<TreeNode*> right = allPossibleFBT(n-1-i);
                for (auto l : left) {
                    for (auto r : right) {
                        TreeNode* root = new TreeNode(0);
                        root->left = l;
                        root->right = r;
                        res.push_back(root);
                    }
                }
            }
        }
        memo[n] = res;
        return res;
    }
};