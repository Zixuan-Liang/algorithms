class MedianFinder {
public:
    /** initialize your data structure here. */
    
    int count;
    multiset<int> smaller_half;
    multiset<int> bigger_half;
    
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        count++;
        smaller_half.insert(num);
        bigger_half.insert(*rbegin(smaller_half));
        smaller_half.erase(--end(smaller_half));
        if (bigger_half.size() > smaller_half.size()) {
            smaller_half.insert(*begin(bigger_half));
            bigger_half.erase(begin(bigger_half));
        }
    }
    
    double findMedian() {
        if (count % 2 == 1) {
            return *rbegin(smaller_half) * 1.0;
        }
        else {
            return (*rbegin(smaller_half) + *begin(bigger_half)) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */