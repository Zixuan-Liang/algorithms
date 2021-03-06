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
    
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
        TreeNode* root = new TreeNode(postorder[postEnd]);
        if (postStart >= postEnd) return root;
        int rootIdx = idxMap[root->val];
        int leftLen = rootIdx - inStart, rightLen = inEnd - rootIdx;
        if (leftLen != 0) root->left = helper(inorder, postorder, inStart, inStart+leftLen-1, postStart, postStart+leftLen-1);
        if (rightLen != 0) root->right = helper(inorder, postorder, inEnd-rightLen+1, inEnd, postEnd-rightLen, postEnd-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) idxMap[inorder[i]] = i;
        return helper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};