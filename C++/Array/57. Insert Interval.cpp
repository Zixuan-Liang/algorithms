class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;
        
        // 一般情况
        // 找出上限和下限，初始化为新区间的上下限
        int left = newInterval[0], right = newInterval[1];
        // 用一个变量保存是否插入了
        bool inserted = false;
        for (auto& v : intervals) {
            // 如果区间整个在新区间前面，什么都不用做，插入到待返回的数组后面
            if (v[1] < left) {
                res.push_back(v);
            }
            // 如果区间整个在新区间后面，但还没插入，说明就应该插在该区间前面
            else if (v[0] > newInterval[1] ) {
                if (!inserted) { res.push_back({left, right}); inserted = true; }
                res.push_back(v);
            }
            // 否则可能需要更新上下限值
            else if (!inserted){
                // 更新下限
                if (v[0] <= newInterval[0] && newInterval[0] <= v[1]) left = v[0];
                // 更新上限，上限一旦更新，即可插入
                if (v[0] <= newInterval[1] && newInterval[1] <= v[1]) { 
                    right = v[1]; 
                    res.push_back({left, right}); inserted = true;
                }
            }
            
        }
        // 遍历完了还没插入，说明需要插在最后
        if (!inserted) res.push_back({left, right});
        return res;
    }
};