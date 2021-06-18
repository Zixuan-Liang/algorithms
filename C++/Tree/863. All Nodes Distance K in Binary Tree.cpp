/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void findParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents) {
        if (root->left) {
            parents[root->left] = root;
            findParents(root->left, parents);
        }
        if (root->right) {
            parents[root->right] = root;
            findParents(root->right, parents);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        parents[root] = nullptr;
        findParents(root, parents);
        
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        vector<int> res;
        int dist = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (dist == k) {
                    res.push_back(node->val);
                }
                else {
                    if (node->left && !visited.count(node->left)) {
                        q.push(node->left);
                        visited.insert(node->left);
                    }
                    if (node->right && !visited.count(node->right)) {
                        q.push(node->right);
                        visited.insert(node->right);
                    }
                    if (parents[node] && !visited.count(parents[node])) {
                        q.push(parents[node]);
                        visited.insert(parents[node]);
                    }
                }
            }
            if (dist == k) break;
            dist++;
        }
        return res;
    }
};






