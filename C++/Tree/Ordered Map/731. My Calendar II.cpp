class MyCalendarTwo {
    map<int, int> treeMap1, treeMap2;
public:
    bool book(int start, int end) {
        auto it = treeMap1.upper_bound(start);
        if (it == treeMap1.end() || it->second >= end) {
            treeMap1[end] = start;
            return true;
        }
        vector<int> toRemove;
        vector<pair<int, int>> toAdd;
        for (; it != treeMap1.end() && it->second < end; it++) {
            int s2 = max(start, it->second);
            int e2 = min(end, it->first);
            if (start > it->second) {
                start = it->second;
            }
            if (end < it->first) {
                end = it->first;
            }
            
            auto it2 = treeMap2.upper_bound(s2);
            if (it2 != treeMap2.end() && it2->second < e2) {
                return false;
            }
            
            toRemove.push_back(it->first);
            toAdd.emplace_back(e2, s2);
        }
        for (int e : toRemove) {
            treeMap1.erase(e);
        }
        treeMap1[end] = start;
        for (const pair<int, int> &p : toAdd) {
            treeMap2[p.first] = p.second;
        }
        return true;
    }
};