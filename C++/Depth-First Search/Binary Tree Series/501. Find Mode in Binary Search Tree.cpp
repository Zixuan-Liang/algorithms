// 中序遍历二叉搜索树，得到的是一个排好序的数组
// 所以中序遍历二叉树，比较相邻的节点，适时更新计数即可

class Solution {
public:
    int maxCount = INT_MIN;
    int currCount = 0;
    TreeNode* prev = NULL;
    vector<int> ans;
    
    // 中序遍历
    void inorder(TreeNode* root, bool getlist){
        if(!root) return;
        
        // 遍历左
        inorder(root->left, getlist);
        
        // 根节点处理
        if(prev && prev->val==root->val) // 如果当前节点和前一个节点值相等，计数+1
            currCount++;
        else                    // 否则计数重置
            currCount=1;        
        if(!getlist) {      // 第一次遍历是为了找出最多的那个数出现次数，更新maxCount
            maxCount = max(maxCount, currCount);
        }
        else if(currCount==maxCount) {  // 第二次遍历找出出现次数等于maxCount的数，存进答案
            ans.push_back(root->val);
        }
        prev = root;

        // 遍历右
        inorder(root->right, getlist);
    }
    
    vector<int> findMode(TreeNode* root) {
        ans.clear();
        if(!root) return ans;
        
        // 第一次遍历是为了找出最多的那个数出现次数
        inorder(root, false);
        
        // 第二次遍历找出出现次数等于maxCount的数，存进答案
        prev = NULL;
        currCount = 0;
        inorder(root, true);
        
        return ans;
    }
};