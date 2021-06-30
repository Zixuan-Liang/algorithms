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
    
    unordered_map<int, int> idxMap;
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        TreeNode* root = new TreeNode(preorder[preStart]);
        if (preStart >= preEnd) return root;
        int rootIdx = idxMap[root->val];
        int leftLen = rootIdx - inStart, rightLen = inEnd - rootIdx;
        if (leftLen != 0) root->left = helper(preorder, inorder, preStart+1, preStart+leftLen, inStart, inStart+leftLen-1);
        if (rightLen != 0) root->right = helper(preorder, inorder, preEnd-rightLen+1, preEnd, inEnd-rightLen+1, inEnd);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) idxMap[inorder[i]] = i;
        return helper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};