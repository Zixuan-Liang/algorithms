class RangeModule {
    
    map<int, int> intervals;
    
public:
    RangeModule() {}
    // 假设一共有n个区间
    // 添加区间，复杂度：O(n) (因为可能要删除多个区间)
    void addRange(int left, int right) {
        // 找出第一个和最后一个可能相交的区间
        auto l = intervals.upper_bound(left), r = intervals.upper_bound(right); // r是最后一个可能相交的区间+1
        // l - 1或者l是第一个可能相交的区间，具体哪一个根据数值判断
        if (l != intervals.begin()) {
            l--;
            if (l->second < left) l++;
        }
        // 如果第一个可能相交的区间和最后一个可能相交的区间+1不相等，说明有相交的区间，需要删除
        if (l != r) {
            left = min(left, l->first); // 找出最后保留的区间下限
            right = max(right, (--r)->second); // 上限
            intervals.erase(l, ++r); // 删除所有相交的区间
        }
        intervals[left] = right;
    }
    // 查询区间，复杂度：O(logn)
    bool queryRange(int left, int right) {
        auto l = intervals.upper_bound(left); // 下限的upper_bound - 1即为可能包含该区间的区间
        if (l == intervals.begin() or (--l)->second < right) { // 上限没被包含，返回false
            return false;
        }
        return true;
    }
    // 删除区间，复杂度：O(n) (因为可能要删除多个区间)
    void removeRange(int left, int right) {
        // 找出第一个和最后一个可能相交的区间
        auto l = intervals.upper_bound(left), r = intervals.upper_bound(right); // r是最后一个可能相交的区间+1
        // l - 1或者l是第一个可能相交的区间，具体哪一个根据数值判断
        if (l != intervals.begin()) {
            l--;
            if (l->second < left) l++;
        }
        // 如果第一个可能相交的区间和最后一个可能相交的区间+1相等，说明没有相交的区间，不需要删除任何区间
        if (l == r) return ;
        // 否则删除一些区间，找出保留的区间的上下限
        int keptL = min(left, l->first), keptR = max(right, (--r)->second);
        intervals.erase(l, ++r); // 删除所有相交的区间
        if (keptL < left) intervals[keptL] = left; // 最左边可能保留一个区间
        if (right < keptR) intervals[right] = keptR; // 最右边可能保留一个区间
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */