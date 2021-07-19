class Solution {
public:
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        unordered_map<string, int> index_lookup;
        for (int i = 0; i < logs.size(); i++) {
            index_lookup[logs[i]] = i;
        }
        
        auto myComp = [&](const string& s1, const string& s2)->bool{
            int space1 = s1.find(" "), space2 = s2.find(" "); 
            string id1 = s1.substr(0, space1), id2 = s2.substr(0, space2);
            string content1 = s1.substr(space1+1), content2 = s2.substr(space2+1);
            bool alpha1 = isalpha(content1[0]), alpha2 = isalpha(content2[0]);
            if (alpha1 == alpha2 && alpha1) { // 都是字母
                return content1 < content2 || (content1 == content2 && id1 < id2);
            }
            else if (alpha1 == alpha2 && !alpha1){ // 都是数字
                return index_lookup[s1] < index_lookup[s2];
            }
            else { // 一个是字母，一个是数字
                return alpha1;
            }
        };
        
        sort(begin(logs), end(logs), myComp);
        return logs;
    }
};