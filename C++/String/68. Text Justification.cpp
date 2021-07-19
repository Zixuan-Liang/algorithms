class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int left = 0, right = 0;
        int currWidth = 0, currCount = 0;
        while (left < words.size()) {
            while (right < words.size() && currWidth + words[right].size() + currCount <= maxWidth) {
                currWidth += words[right].size();
                currCount++;
                right++;
            }
            string s;
            if (right == words.size() || currCount == 1) {
                s = words[left];
                for (int i = left+1; i < right; i++) {
                    s += " " + words[i];
                }
                s += string(maxWidth - s.size(), ' ');
            }
            else {
                int spaceWidth = maxWidth - currWidth;
                int perSpace = spaceWidth / (currCount - 1);
                int residual = spaceWidth % (currCount - 1);
                s = words[left];
                for (int i = left+1; i < left+1+residual; i++) {
                    s += string(perSpace+1, ' ') + words[i];
                }
                for (int i = left+1+residual; i < right; i++) {
                    s += string(perSpace, ' ') + words[i];
                }
            }
            res.push_back(s);
            left = right;
            currWidth = 0; currCount = 0;
        }
        return res;
    }
};