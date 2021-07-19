class Solution {
    
    int n;
    vector<int> tree;
    
public:
    
    void buildTree(int treePos, int left, int right) {
        if (left == right) {
            tree[treePos] = 1;
        }
        else {
            int mid = left + (right - left) / 2;
            buildTree(treePos * 2, left, mid);
            buildTree(treePos * 2 + 1, mid + 1, right);
            tree[treePos] = tree[treePos * 2] + tree[treePos * 2 + 1];
        }
    }
    
    void queryUpdate(int treePos, int left, int right, int k, int& index) {
        if (left == right) {
            tree[treePos]--;
            index = left;
        }
        else {
            int mid = left + (right - left) / 2;
            if (k < tree[treePos * 2]) {
                tree[treePos]--;
                queryUpdate(treePos * 2, left, mid, k, index);
            }
            else {
                tree[treePos]--;
                k -= tree[treePos * 2];
                queryUpdate(treePos * 2 + 1, mid + 1, right, k, index);
            }
        }
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& p1, const vector<int>& p2)->bool {
            return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] > p2[1]);
        });
        n = people.size();
        tree = vector<int>(4*n, 0);
        buildTree(1, 0, n-1);
        vector<vector<int>> ans(n);
        for (auto& person : people) {
            int index;
            queryUpdate(1, 0, n-1, person[1], index);
            ans[index] = person;
        }
        return ans;
    }
};