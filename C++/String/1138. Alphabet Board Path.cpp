class Solution {
public:
    
    vector<int> coordinate(char c) {
        int n = c - 'a';
        int row = n / 5;
        int col = n % 5;
        return {row, col};
    }
    
    string move(char prev, char next) {
        if (prev == next) return "";
        vector<int> prevPos = coordinate(prev);
        vector<int> nextPos = coordinate(next);
        int x = nextPos[0] - prevPos[0];
        int y = nextPos[1] - prevPos[1];
        string res = "";
        if (x <= 0 && y >= 0) {
            for (int i = 0; i < abs(x); i++) {
                res += 'U';
            }
            for (int i = 0; i < abs(y); i++) {
                res += 'R';
            }
        }
        else {
            for (int i = 0; i < abs(y); i++) {
                if (y <= 0) res += 'L';
                else res += 'R';
            }
            for (int i = 0; i < abs(x); i++) {
                if (x <= 0) res += 'U';
                else res += 'D';
            }
        }
        return res;
    }
    
    string alphabetBoardPath(string target) {
        char prev = 'a';
        string res = "";
        for (char c : target) {
            res += move(prev, c);
            res += '!';
            prev = c;
        }
        return res;
    }
};