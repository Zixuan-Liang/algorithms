/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
        
    queue<string> split(string& s, string del = " ") {
        queue<string> res;
        int start = 0;
        int end = s.find(del);
        while (end != -1) {
            res.push(s.substr(start, end - start));
            start = end + del.size();
            end = s.find(del, start);
        }
        res.push(s.substr(start, end - start));
        return res;
    }

    void serializeHelper(TreeNode* root, string& data) {
        if (!root) {
            data += "#,";
        }
        else {
            data += to_string(root->val) + ",";
            serializeHelper(root->left, data);
            serializeHelper(root->right, data);
        }
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data = "";
        serializeHelper(root, data);
        return data;
    }

    TreeNode* deserilizeHelper(queue<string>& nodes) {
        if (nodes.empty()) {
            return nullptr;
        }
        else {
            string val = nodes.front();
            nodes.pop();
            if (val == "#") {
                return nullptr;
            }
            else {
                TreeNode* root = new TreeNode(stoi(val));
                root->left = deserilizeHelper(nodes);
                root->right = deserilizeHelper(nodes);
                return root;
            }
        }
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes = split(data, ",");
        return deserilizeHelper(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));