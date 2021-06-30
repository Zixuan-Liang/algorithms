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
class BSTIterator {
    
    vector<int> traversal;
    int curr;
    
public:
    
    void inorder(TreeNode* root, vector<int>& traversal) {
        if (!root) {
            return ;
        }
        inorder(root->left, traversal);
        traversal.push_back(root->val);
        inorder(root->right, traversal);
    }
    
    BSTIterator(TreeNode* root) {
        traversal.push_back(INT_MIN);
        curr = 0;
        inorder(root, traversal);
    }
    
    int next() {
        return traversal[++curr];
    }
    
    bool hasNext() {
        return curr < traversal.size() - 1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */