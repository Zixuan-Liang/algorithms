class Solution {
public:
    int maxCount = INT_MIN;
    int currCount = 0;
    TreeNode* prev = NULL;
    vector<int> ans;
    
    void inorder(TreeNode* root, bool getlist){
        if(!root) return;
        
        inorder(root->left, getlist);
        
        if(prev && prev->val==root->val)
            currCount++;
        else
            currCount=1;
        if(!getlist) maxCount = max(maxCount, currCount);
        else if(currCount==maxCount) ans.push_back(root->val);
        prev = root;
        inorder(root->right, getlist);
    }
    
    vector<int> findMode(TreeNode* root) {
        ans.clear();
        if(!root) return ans;
        
        // Get the maxCount size
        inorder(root, false);
        
        // Get the final list
        prev = NULL;
        currCount = 0;
        inorder(root, true);
        
        return ans;
    }
};