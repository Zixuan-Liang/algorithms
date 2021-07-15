// 线段树实现数组的范围和查询，数组的值可以被修改
// 复杂度：数组长度为n
// 建树：时间：O(n)，空间：O(n)
// 更新：时间：O(logn)
// 查询：时间：O(logn)

class NumArray {
    
    int n;
    vector<int> tree; // 用数组表示树，开辟的空间应为4 * n，n为原数组的长度
    
public:
    // 递归方法建树，树根从1开始，则当父节点为x，左孩子为2x，右孩子为2x+1
    void buildTree(vector<int>& nums, int node, int left, int right) {
        if (left == right) { // 叶节点
            tree[node] = nums[left];
        }
        else {
            int mid = left + (right - left) / 2;
            buildTree(nums, node * 2, left, mid); // 建左树
            buildTree(nums, node * 2 + 1, mid + 1, right); // 建右树
            tree[node] = tree[node * 2] + tree[node * 2 + 1]; // push up
        }
    }
    // 更新树，传入参数：树根节点索引（1），原数组开始索引（0），原数组结束索引（n-1），更新数值所在原数组索引，更新的数值
    void updateTree(int node, int left, int right, int index, int val) {
        if (left == right) { // 访问到对应叶节点，直接修改
            tree[node] = val;
        }
        else {
            int mid = left + (right - left) / 2;
            if (index <= mid) { // 更新数值所在索引与mid比较，决定更新的是左树还是右树，递归调用
                updateTree(node * 2, left, mid, index, val);
            }
            else { 
                updateTree(node * 2 + 1, mid + 1, right, index, val);
            }
            tree[node] = tree[node * 2] + tree[node * 2 + 1]; // push up
        }
    }
    // 查询范围之和，传入参数：树根节点索引（1），原数组开始索引（0），原数组结束索引（n-1），查询的开始索引，查询的结束索引
    int queryTree(int node, int left, int right, int queryLeft, int queryRight) {
        if (queryRight < left or right < queryLeft) { // 查询的范围完全超出树节点对应范围，返回0
            return 0;
        }
        else if (queryLeft <= left and right <= queryRight) { // 查询的范围完全包含树节点对应范围，返回节点对应值
            return tree[node];
        }
        else { // 否则分别到左右子树递归查询
            int mid = left + (right - left) / 2;
            int q1 = queryTree(node * 2, left, mid, queryLeft, queryRight);
            int q2 = queryTree(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
            return q1 + q2; // 合并
        }
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree = vector<int>(4*n, 0);
        buildTree(nums, 1, 0, n-1);
    }
    
    void update(int index, int val) {
        updateTree(1, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return queryTree(1, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */