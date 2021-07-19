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

// class SegmentTreeNode
// {
// public:
//     vector<int> x;
//     long x_width_sum;    
//     int cnt;            //[l, r)被重复了几次
//     int l, r;
//     SegmentTreeNode * left, * right;

//     SegmentTreeNode()
//     {}

//     SegmentTreeNode (int _l, int _r, vector<int> & _x)
//     {
//         this->x = _x;
//         this->x_width_sum = 0;
//         this->cnt = 0;
//         this->l = _l,    this->r = _r;
//         this->left = NULL,  this->right = NULL;
//     }

//     int mid()   //计算中间值
//     {
//         return (this->l + this->r) / 2;
//     }

//     SegmentTreeNode * _left()    //获得左孩子
//     {
//         if (this->left == NULL)
//             this->left = new SegmentTreeNode(this->l, mid(), x);
//         return this->left;
//     }
//     SegmentTreeNode * _right()   //获得右孩子
//     {
//         if (this->right == NULL)
//             this->right = new SegmentTreeNode(mid(), this->r, x);
//         return this->right;
//     }

//     void update(int ul, int ur, int diff)
//     {
//         if (ul >= ur)
//             return ;
//         if (this->l == ul && this->r == ur)
//             this->cnt += diff;
//         else
//         {
//             _left()->update (ul, min(mid(), ur), diff );
//             _right()->update(max(mid(), ul), ur, diff );
//         }
//         if (this->cnt > 0)
//             this->x_width_sum = x[r] - x[l];
//         else
//             this->x_width_sum = _left()->x_width_sum + _right()->x_width_sum;
//     }

//     long query()
//     {
//         return this->x_width_sum;
//     }

// };


// class Solution 
// {
// public:
//     int rectangleArea(vector<vector<int>>& rectangles) 
//     {
//         int MOD = 1e9 + 7;
//         int OPEN = 1;
//         int CLOSE = -1;
//         vector<tuple<int,int,int,int>> rec;
//         set<int> x_set;
//         for (auto v: rectangles)
//         {
//             int x1 = v[0],  y1 = v[1],  x2 = v[2],  y2 = v[3];
//             rec.push_back(tuple<int,int,int,int>{y1, OPEN, x1, x2});
//             rec.push_back(tuple<int,int,int,int>{y2, CLOSE, x1, x2});
//             x_set.insert(x1);
//             x_set.insert(x2);
//         }

//         sort(rec.begin(), rec.end());
//         vector<int> x(x_set.begin(), x_set.end());  //去重
//         int n = x.size();
//         unordered_map<int,int> x_idx;           //离散化
//         for (int i = 0;  i < n; i ++)
//             x_idx[x[i]] = i;
        
//         long res = 0;
//         SegmentTreeNode * activate = new SegmentTreeNode(0, n - 1, x);
//         int cur_y =  get<0>(rec[0]);
//         for (auto [y, state,  x1, x2] : rec)
//         {
//             res += activate->query() * (y - cur_y);
//             res %= MOD;
//             activate->update(x_idx[x1], x_idx[x2], state);
//             cur_y = y;
//         }

//         return res;
//     }
// };