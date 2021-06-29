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
class CBTInserter {
    
    TreeNode* root;
    queue<TreeNode*> notFilled;
    
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node->left || !node->right) {
                notFilled.push(node);
            }
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    
    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        notFilled.push(node);
        TreeNode* parent = notFilled.front();
        if (!parent->left) {
            parent->left = node;
        }
        else {
            parent->right = node;
            notFilled.pop();
        }
        return parent->val;
    }
    
    TreeNode* get_root() {
        return this->root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */