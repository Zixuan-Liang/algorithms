// Statement: If M operations, either Union or Find, are applied to N elements, 
// the total run time is O(Mlog*N), where log* is the iterated logarithm, 
// can be seen as constant.
// Let N be the number of input equations and M be the number of queries.
// Time Complexity: O((M+N)log*N)
// Space Complexity: O(N)

class Solution {
public:
    
    unordered_map<string, string> parents;
    unordered_map<string, double> vals;
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res(queries.size());
        for (int i = 0; i < values.size(); i++) {
            uni(equations[i][0], equations[i][1], values[i]);
        }
        for (int i = 0; i < queries.size(); i++) {
            string x = queries[i][0], y = queries[i][1];
            res[i] = (parents.count(x) && parents.count(y) && find(x)==find(y)) ? vals[x] / vals[y] : -1.0;
        }
        return res;
    }
    
    void add(string x) {
        if (parents.count(x)) {
            return ;
        }
        parents[x] = x;
        vals[x] = 1.0;
    }
    
    string find(string x) {
        string p = parents[x];
        if (x != p) {
            parents[x] = find(p);
            vals[x] = vals[x] * vals[p];
        }
        return parents[x];
    }
    
    void uni(string x, string y, double v) {
        add(x);
        add(y);
        string px = find(x), py = find(y);
        parents[px] = py;
        vals[px] = v * vals[y] / vals[x];
    }
};