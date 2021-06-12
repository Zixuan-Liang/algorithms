class MovingAverage {
    
    queue<int> q;
    int sum = 0;
    int sz;
    
public:
    /** Initialize your data structure here. */
    MovingAverage(int size): sz(size) {
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > sz) {
            sum -= q.front();
            q.pop();
        }
        return 1.0 * sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */