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
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> umap;
        for (string& path : paths) {
            vector<string> tokens = split(path);
            string folder = tokens[0];
            for (int i = 1; i < tokens.size(); i++) {
                string token = tokens[i];
                vector<string> info = split(token, "(");
                string file = info[0], content = info[1];
                umap[content].push_back(folder + "/" + file);
            }
        }
        
        vector<vector<string>> res;
        for (auto& [content, files] : umap) {
            if (files.size() > 1) res.push_back(files);
        }
        return res;
    }
};