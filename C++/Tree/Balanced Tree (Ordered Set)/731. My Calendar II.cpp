class MyCalendarTwo {
private:
    map<int, int> m;
public:
    
    //Parameter n sets the max number of bookings allowed to overlap
    //if n is set to 2 it will check for existing double bookings
    //if n is set to 3 if will check for existing triple bookings etc
    bool exists(int n){
        int count = 0;
        for (auto entry: m){
            count+=entry.second;
            if(count>=n) return true;
        }
        return false;
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        if(!exists(3)) return true;//Check for triple booking (n=2)
        else{//restore the original counts since we are not booking this room
            m[start]--;
            m[end]++;
            return false;
        }
    }
};