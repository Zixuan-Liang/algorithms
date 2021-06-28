#include <map>

// 平衡树 Ordered Set
// 复杂度：事件数n，时间O(n^2)（添加所有事件），空间O(n)
class MyCalendarThree {
    
    map<int, int> events;
    
public:
    MyCalendarThree() {
        
    }
    
    // 查找已存在的事件中，同时存在的最大事件数
    // 由731 exists(int n)修改而成，此处不跳出循环，需要遍历所有事件，更新最大共存值
    int maxExists() {
        int ans = 0;
        int count = 0;
        for (auto [time, freq] : events) {
            count += freq;
            ans = max(ans, count);
        }
        return ans;
    }
    
    int book(int start, int end) {
        events[start]++;
        events[end]--;
        return maxExists();
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */