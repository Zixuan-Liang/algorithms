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
    
    int lengthLongestPath(string input) {
        int ans = 0;
        vector<string> lines = split(input, "\n");
        unordered_map<int, int> pathLen;
        pathLen[0] = 0;
        for (string& line : lines) {
            vector<string> s = split(line, "\t");
            int depth = s.size() - 1;
            string name = s.back();
            int tmp = pathLen[depth] + name.size();
            if (name.find(".") != -1) {
                ans = max(ans, tmp);
            }
            else {
                pathLen[depth + 1] = tmp + 1;
            }
        }
        return ans;
    }
};