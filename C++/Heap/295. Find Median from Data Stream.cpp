class MedianFinder {
    
    int count;
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        count++;
        lower.push(num);
        upper.push(lower.top());
        lower.pop();
        if (lower.size() < upper.size()) {
            lower.push(upper.top());
            upper.pop();
        }
    }
    
    double findMedian() {
        if (count % 2 == 1) {
            return 1.0 * lower.top();
        }
        else {
            return (lower.top() + upper.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */