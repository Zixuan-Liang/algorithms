class MyCalendarThree {
    
    map<int, int> events;
    
public:
    MyCalendarThree() {
        
    }
    
    // bool exists(int n){
    //     int count = 0;
    //     for (auto entry: events){
    //         count+=entry.second;
    //         if(count>=n) return true;
    //     }
    //     return false;
    // }
    
    int maxExists() {
        int ans = 0;
        int count = 0;
        for (auto entry : events) {
            count += entry.second;
            ans = max(ans, count);
        }
        return ans;
    }
    
    int book(int start, int end) {
        events[start]++;
        events[end]--;
        // int low = 1, high = events.size() + 1;
        // while (low < high) {
        //     int mid = low + (high - low) / 2;
        //     if (exists(mid)) {
        //         low = mid + 1;
        //     }
        //     else {
        //         high = mid;
        //     }
        // }
        // return low - 1;
        return maxExists();
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */