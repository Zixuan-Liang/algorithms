class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;
        unordered_map<string, unordered_set<string>> graph;
        for (auto& acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                string email = acc[i];
                graph[email].insert(acc[1]);
                graph[acc[1]].insert(email);
                emailToName[email] = name;
            }
        }
        
        unordered_set<string> seen;
        vector<vector<string>> res;
        for (auto& item : graph) {
            string email = item.first;
            if (seen.find(email) == seen.end()) {
                seen.insert(email);
                vector<string> stack = {email};
                vector<string> component;
                while (!stack.empty()) {
                    string node = stack.back();
                    stack.pop_back();
                    component.push_back(node);
                    for (string nei : graph[node]) {
                        if (seen.find(nei) == seen.end()) {
                            seen.insert(nei);
                            stack.push_back(nei);
                        }
                    }
                }
                sort(component.begin(), component.end());
                component.insert(component.begin(), emailToName[email]);
                res.push_back(component);
            }
        }
        return res;
    }
};