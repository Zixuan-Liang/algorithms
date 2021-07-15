class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].first.push_back(timestamp);
        m[key].second.push_back(value);
    }
    
    string get(string key, int timestamp) {
        auto it = upper_bound(m[key].first.begin(), m[key].first.end(), timestamp);
        return it == m[key].first.begin() ? "" : m[key].second[it - 1 - m[key].first.begin()];
    }
private:
    unordered_map<string, pair<vector<int>,vector<string>>> m;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

