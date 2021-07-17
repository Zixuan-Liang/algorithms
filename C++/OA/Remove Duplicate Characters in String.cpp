#include <unordered_set>
#include <unordered_map>

class solution {

public:

    // keep 1 of the duplicates
    string removeDuplicate(string s) {
        unordered_set<char> seen;
        string res = "";
        for (char c : s) {
            if (seen.find(c) == seen.end()) {
                res += c;
            }
        }
        return res;
    }

    // keep 0 of the duplicates
    string removeDuplicate(string s) {
        unordered_map<char> charCount;
        for (char c : s) charCount[c]++;
        string res = ""
        for (char c : s) {
            if (charCount[c] < 2) {
                res += c;
            }
        }
        return res;
    }

}