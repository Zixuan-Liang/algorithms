class PhoneDirectory {
    
    unordered_set<int> available;
    int maxNums;
    
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        maxNums = maxNumbers;
        for (int i = 0; i < maxNums; i++) available.insert(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (available.empty()) {
            return -1;
        }
        else {
            int res = *available.begin();
            available.erase(res);
            return res;
        }
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return available.find(number) != available.end();
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        available.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */