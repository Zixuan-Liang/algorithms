class Solution {
public:
    int reversePairs(vector<int>& nums) {
        set<int> s;
        for (int& x : nums) s.insert(x);
        vector<long long> v;
        for (auto it = s.begin(); it != s.end(); it++) v.push_back(*it);
        unordered_map<int, int> m;
        for (int i = 0; i < v.size(); i++) m[v[i]] = i;
        int n = v.size(), ret = 0;
        vector<int> segtree(2 * n);
        for (int i = nums.size()-1; i >= 0; i--)
        {
            if (v[0] * 2 < nums[i])
            {
                int left = 0, right = n-1, mid = (right + 1) / 2;
                while (left < right)
                {
                    if (v[mid] * 2 < nums[i]) left = mid;
                    else right = mid - 1;
                    mid = (left + right + 1) / 2;
                }
                ret += query(segtree, 0, mid, n);
            }
            update(segtree, m[nums[i]], n);
        }
        return ret;
    }
    int query(vector<int>& segtree, int a, int b, int n)
    {
        int ret = 0;
        for (a += n, b += n; a <= b; a >>= 1, b >>= 1)
        {
            if (a & 1) ret += segtree[a++];
            if (!(b & 1)) ret += segtree[b--];
        }
        return ret;
    }
    void update(vector<int>& segtree, int a, int n)
    {
        for (a += n; a; a >>= 1) segtree[a]++;
    }
};