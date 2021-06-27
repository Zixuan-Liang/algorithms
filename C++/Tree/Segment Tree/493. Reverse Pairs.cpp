typedef long long int lli;

class Solution {
private:
    void update(vector<int>& tree, int n, int idx, int val) {
        idx += n;
        tree[idx] += val;
        for (int i=idx; i>1; i>>=1) tree[i>>1] = tree[i] + tree[i^1];
    }
    int query(vector<int>& tree, int n, int pos) {
        int l = pos + n, r = 2 * n, sum = 0;
        for (; l<r; l>>=1, r>>=1) {
            if (l & 1) sum += tree[l++];
            if (r & 1) sum += tree[--r];
        }
        return sum;
    }
    int getIndex(int *a, int n, lli val) {
        return lower_bound(a, a+n, val) - a;
    }
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size(), inversions = 0;
        int temp[n];
        vector<int> tree(n<<1,0);
        for (int i=0; i<n; i++) temp[i] = nums[i];
        sort(temp, temp+n);
        for (lli num : nums) {
            inversions += query(tree, n, getIndex(temp, n, num*2+1));
            update(tree, n, getIndex(temp, n, num), 1);
        }
        return inversions;
    }
};