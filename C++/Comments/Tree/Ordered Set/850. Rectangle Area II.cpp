// 利用multiset进行多区间查询（可用线段树优化）
// 复杂度：O(n^2)（可用线段树优化为O(nlogn)）
// 排序O(nlogn) + 扫描O(n) * 查询O(n) = O(n^2)

class Solution 
{
public:
    int rectangleArea(vector<vector<int>>& rectangles) 
    {
        //从左往右，线性扫描
        int MOD = 1e9 + 7;
        int OPEN = 0;
        int CLOSE = 1;
        vector<tuple<int,int,int,int>> rec;
        for (auto v: rectangles)
        {
            int x1 = v[0], y1 = v[1], x2 = v[2], y2 = v[3];
            rec.push_back({x1, OPEN, y1, y2});
            rec.push_back({x2, CLOSE, y1, y2});
        }
        sort(rec.begin(), rec.end()); // 从左到右扫描，所以需要对x排序，对相同的x则位于矩阵左边线的x排在前面

        multiset<pair<int,int>> activate;

        // 查询y方向上多个重叠区间加起来的长度，作为“矩形”的高，复杂度：O(n)，这里可以用线段树实现优化，改进为O(logn)
        std::function<int ()> query = [&]()
        {
            int res = 0;
            int D = -1;
            for  (auto [y1, y2] : activate)
            {
                D = max(D, y1);
                res += max(0, y2 - D);
                D = max(D, y2);
            }
            return res;
        };

        int cur_x = get<0>(rec[0]);
        long res = 0;
        // 复杂度：O(n^2)，因为query需要O(n)时间，如果用线段树优化query，时间复杂度为O(nlogn)
        for (auto [x, state, y1, y2] : rec)
        {
            res += (long long)query() * (x - cur_x); // query返回当前x和上一个x之间的“高”
            res %= MOD;
            if (state == OPEN)
                activate.insert({y1, y2});
            else
                activate.erase(activate.find(pair<int,int>{y1, y2}));
            cur_x = x;
        }
        return res;

    }
};