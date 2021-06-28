#include <map>

// 平衡树 Ordered Set
// 复杂度：事件数n，时间O(nlogn)（添加所有事件），空间 O(n)
class MyCalendar {
    
    map<int, int> events;
    
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto ub = events.upper_bound(start);
        auto lb = events.lower_bound(end);
        if (ub != lb) { // 开始时间的upper_bound不等于结束时间的lower_bound，说明有重叠
            return false;
        }
        else if (ub != events.begin() && (--ub)->second > start) { // 开始时间的upper_bound-1结束时间大于开始时间，说明有重叠
            return false;
        }
        else {
            events[start] = end;
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */