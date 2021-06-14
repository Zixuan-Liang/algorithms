class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.size() != end.size()) return false;
        
        vector<pair<char, int>> A, B;
        for (int i = 0; i < start.size(); i++) {
            if (start[i] == 'L' || start[i] == 'R')
                A.push_back({start[i], i});
        }
        for (int i = 0; i < end.size(); i++) {
            if (end[i] == 'L' || end[i] == 'R')
                B.push_back({end[i], i});
        }
        
        if (A.size() != B.size()) return false;
        
        for (int i = 0; i < A.size(); i++) {
            if (A[i].first != B[i].first) {
                return false;
            }
            else if (A[i].first == 'L' && A[i].second < B[i].second
                    || A[i].first == 'R' && A[i].second > B[i].second) {
                return false;
            }
        }
        return true;
    }
};