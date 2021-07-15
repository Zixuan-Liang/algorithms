/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    
    int position = -1;
    vector<int> vec;
    
public:
    
    // isInteger: 可以用typeid(k).name()来判断数据类型
    
    void flattenList(vector<NestedInteger>& nestedList, vector<int>& vec) {
        for (auto& l : nestedList) {
            if (l.isInteger()) {
                vec.push_back(l.getInteger());
            }
            else {
                flattenList(l.getList(), vec);
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattenList(nestedList, vec);
        position = -1;   
    }
    
    int next() {
        position++;
        return vec[position];
    }
    
    bool hasNext() {
        return position+1<vec.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */