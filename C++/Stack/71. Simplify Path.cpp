class Solution {
public:
    string simplifyPath(string path) {
        deque<string> stk;
        string currStr = "";
        int index = 0;
        while (index < path.size()) {
            if (path[index] == '/') {
                if (currStr != "") stk.push_back(currStr);
                currStr = "";
                index++;
            }
            else if (path[index] == '.'){
                // pattern: /../
                if (path.substr(index-1, 3) == "/.." && (index+2 >= path.size() || path[index+2] == '/')) {
                    if (!stk.empty()) stk.pop_back();
                    currStr = "";
                    index++;
                }
                // pattern /./
                else if (path.substr(index-1, 2) == "/." && (index+1 >= path.size() || path[index+1] == '/')) {
                    currStr = "";
                }
                // otherwise treated as directory/file name
                else {
                    currStr += '.';
                }
                index++;
            }
            else {
                while (index < path.size() && path[index] != '/') {
                    currStr += path[index];
                    index++;
                }
            }
        }
        if (currStr!="") stk.push_back(currStr);
        if (stk.empty()) return "/";
        string res = "";
        while (!stk.empty()) {
            res += "/" + stk.front();
            stk.pop_front();
        }
        return res;
    }
};