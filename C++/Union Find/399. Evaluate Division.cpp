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