class Solution {
public:
    
    vector<string> split(string& s, string del = " ") {
        vector<string> res;
        int start = 0;
        int end = s.find(del);
        while (end != -1) {
            res.push_back(s.substr(start, end - start));
            start = end + del.size();
            end = s.find(del, start);
        }
        res.push_back(s.substr(start, end - start));
        return res;
    }
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string, int> umap;
        for (string& domain : cpdomains) {
            vector<string> v1 = split(domain);
            int count = stoi(v1[0]);
            vector<string> v2 = split(v1[1], ".");
            string s = v2.back();
            umap[s] += count;
            for (int i = size(v2) - 2; i >= 0; i--) {
                s = v2[i] + '.' + s;
                umap[s] += count;
            }
        }
        for (auto [key, value] : umap) {
            ans.push_back(to_string(value) + ' ' + key);
        }
        return ans;
    }
};