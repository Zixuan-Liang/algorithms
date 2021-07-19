class Solution {
public:
    int compress(vector<char>& chars) {
        char prev = ' ';
        int count = 1;
        int index = 0;
        for (char c : chars) {
            if (c != prev) {
                string group_length = to_string(count);
                if (prev != ' ') {
                    chars[index++] = prev;
                    if (group_length != "1") {
                        for (int i = 0; i < group_length.size(); i++) {
                            chars[index++] = group_length[i];
                        }
                    }
                }
                count = 1;
            }
            else {
                count++;
            }
            prev = c;
        }
        chars[index++] = prev;
        if (count > 1) {
            string group_length = to_string(count);
            for (int i = 0; i < group_length.size(); i++) {
                chars[index++] = group_length[i];
            }
        }
        return index;
    }
};
