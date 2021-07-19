class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](const string& a, const string& b)->bool {
            return a.size() > b.size() || (a.size() == b.size() && a < b);
        });
        for (string word : dictionary) {
            int i = 0, j = 0;
            while (i < word.size() && j < s.size()) {
                if (word[i] == s[j]) {
                    i++;
                    j++;
                }
                else {
                    j++;
                }
            }
            if (i >= word.size()) {
                return word;
            }
        }
        return "";
    }
};