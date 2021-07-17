#include <map>

// 平衡树 Ordered Set
// 复杂度：事件数n，时间O(nlogn)（添加所有事件），空间 O(n)
class MyCalendar {
    
    map<int, int> events;
    
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto lb1 = events.lower_bound(start);
        auto lb2 = events.lower_bound(end);
        if (lb1 != lb2) { // 开始时间的lower_bound不等于结束时间的lower_bound，说明有重叠
            return false;
        }
        else if (lb1 != events.begin() && (--lb1)->second > start) { // 开始时间的lower_bound-1结束时间大于开始时间，说明有重叠
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