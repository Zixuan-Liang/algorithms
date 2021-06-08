class RLEIterator {
    
    vector<long> count;
    vector<int> nums;
    long curr;
    
public:
    RLEIterator(vector<int>& encoding) {
        int n = encoding.size() / 2;
        long running = 0;
        for (int i = 0; i < n; i++) {
            if (encoding[2 * i] != 0) {
                running += encoding[2 * i];
                count.push_back(running);
                nums.push_back(encoding[2 * i + 1]);
            }
        }
        curr = 0;
    }
    
    int next(int n) {
        curr += n;
        if (curr > count.back()) {
            return -1;
        }
        else {
            auto lower = lower_bound(count.begin(), count.end(), curr);
            return nums[lower - count.begin()];
        }
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */