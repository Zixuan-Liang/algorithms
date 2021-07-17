#include <map>

// 平衡树 Ordered Set
// 复杂度：事件数n，时间O(n^2)（添加所有事件），空间O(n)
class MyCalendarTwo {
    
    map<int, int> events;
    
public:
    MyCalendarTwo() {
        
    }
    
    // 检查已存在的事件中，是否有n个事件同时存在，triple booking则检查n=3
    bool exists(int n) {
        int count = 0;
        for (auto [time, freq] : events) {
            count += freq;
            if (count >= n) {
                return true;
            }
        }
        return false;
    }
    
    // 事件
    // start1(+1) ---------------------------------------------- end1(-1)
    //                start2(+1)-------------------------- end2(-1)
    //                              start3(+1)------------------------------end3(-1)
    //                                                 ^
    //                                          此处count=2，存在triple booking
    bool book(int start, int end) {
        events[start]++;
        events[end]--;
        if (!exists(3)) {
            return true;
        }
        else {
            events[start]--; // 因为有重叠，不能添加，撤销操作
            events[end]++;
            return false;
        }
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */