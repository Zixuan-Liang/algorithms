class Solution {
public:
    string findReplaceString(string s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        if (indexes.size() == 0) return s;
        vector<tuple<int, string, string>> v;
        for (int i = 0; i < indexes.size(); i++) {
            v.push_back({indexes[i], sources[i], targets[i]});
        }
        sort(v.begin(), v.end(), [](const tuple<int, string, string>& t1, const tuple<int, string, string>& t2)->bool {
            return get<0>(t1) < get<0>(t2);
        });
        string res = "";
        for (int i = 0; i < v.size(); i++) {
            int start = i==0 ? 0 : get<0>(v[i-1])+get<1>(v[i-1]).size();
            int index = get<0>(v[i]);
            res += s.substr(start, index - start);
            string source = get<1>(v[i]), target = get<2>(v[i]);
            if (s.substr(index, source.size()) == source) {
                res += target;
            }
            else {
                res += s.substr(index, source.size());
            }
            if (i == v.size() - 1 && index + source.size() < s.size()) {
                res += s.substr(index + source.size());
            }
        }
        return res;
    }
};