#include <vector>
#include <string>

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