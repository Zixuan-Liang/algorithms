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

// Let res[0] be tree less than or equal to V, res[1] be tree greater than V.

// Detailed explanation: First of all, we can see that the given root is always there in the answer (either in the bigger subtree or in the smaller subtree). After that, if root->val > V, there is a chance that there is some subtree within the subtree root->left which maybe greater than V and that subtree needs to be attached to root->left. Now, we see that this problem of finding "subtree in root->left which is greater than V" is the same as the current problem of splitting root. So we can recurse on left and get the required results. One thing to worry about is, what if there is no subtree in root->left that is greater than V? This case is handled automatically by the base case.
// Similar argument applies for the case root->val <= V.

class Solution {
public:

    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode *> ans(2, nullptr);
        if(root == nullptr) return ans;
        
        if(root->val > V){
            ans[1] = root;
            auto l = splitBST(root->left, V);
            root->left = l[1];
            ans[0]=l[0];
        }else{
            ans[0] = root;
            auto r = splitBST(root->right, V);
            root->right = r[0];
            ans[1] = r[1];
        }
        
        return ans;
    }
    
};