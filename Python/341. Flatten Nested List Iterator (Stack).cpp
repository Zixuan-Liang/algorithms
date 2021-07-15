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
    
    stack<vector<NestedInteger>> listStk;
    stack<int> indexStk;
    
public:
    
    // isInteger: 可以用typeid(k).name()来判断数据类型
    
    void makeStackTopAnInteger() {
        while (!listStk.empty()) {
            vector<NestedInteger>& currList = listStk.top();
            int currIndex = indexStk.top();
            
            if (currList.size() == currIndex) {
                listStk.pop();
                indexStk.pop();
                continue;
            }
            
            if (currList[currIndex].isInteger()) {
                break;
            }
            
            vector<NestedInteger>& newList = currList[currIndex].getList();
            indexStk.top()++;
            listStk.push(newList);
            indexStk.push(0);
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        listStk.push(nestedList);
        indexStk.push(0);
    }
    
    int next() {
        makeStackTopAnInteger();
        vector<NestedInteger>& currList = listStk.top();
        int currIndex = indexStk.top();
        indexStk.top()++;
        return currList[currIndex].getInteger();
    }
    
    bool hasNext() {
        makeStackTopAnInteger();
        return listStk.size() > 0;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */