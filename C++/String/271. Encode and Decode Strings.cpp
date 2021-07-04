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

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (string &str: strs) {
            int len = str.size();
            encoded += to_string(len) + "@" + str;
        }
        
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> r;
        int head = 0;
        while (head < s.size())    {
            int at_pos = s.find_first_of('@', head);
            int len = stoi(s.substr(head, at_pos - head));
            head = at_pos + 1;
            r.push_back(s.substr(head, len));
            head += len;
        }
        
        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));