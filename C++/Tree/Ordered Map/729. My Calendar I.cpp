class MyCalendar {
    
    map<int, int> events;
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto startUpper = events.upper_bound(start);
        auto endLower = events.lower_bound(end);
        if (startUpper != endLower) return false;
        if (startUpper == events.begin() || start >= (--startUpper)->second) {
            events[start] = end;
            return true;
        }
        else return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */