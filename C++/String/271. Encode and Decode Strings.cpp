class Codec {
    
    string delimiter = string(char(257), 1);
    
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
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            ans += delimiter + strs[i];
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        return split(s, delimiter);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));