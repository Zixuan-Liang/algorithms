class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uset;
        for (string& email : emails) {
            int atSign = email.find('@');
            string simplified = "";
            int index = 0;
            while (index < atSign && email[index] != '+') {
                if (email[index] != '.') {
                    simplified += email[index];
                }
                index++;
            }
            simplified += email.substr(atSign);
            uset.insert(simplified);
        }
        return uset.size();
    }
};