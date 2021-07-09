class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> scores;
        for (auto& item : items) {
            int student = item[0], score = item[1];
            scores[student].push(score);
            if (scores[student].size() > 5) {
                scores[student].pop();
            }
        }
        vector<vector<int>> ans;
        for (auto [student, topFive] : scores) {
            int sum = 0;
            while (!topFive.empty()) {
                sum += topFive.top();
                topFive.pop();
            }
            ans.push_back({student, sum / 5});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};