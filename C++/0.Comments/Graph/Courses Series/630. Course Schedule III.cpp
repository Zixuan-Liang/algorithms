class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& c1, const vector<int>& c2)->bool {
            return c1[1] < c2[1];
        });
        priority_queue<int> q;
        int time = 0;
        for (auto& course : courses) {
            if (time + course[0] <= course[1]) {
                q.push(course[0]);
                time += course[0];
            }
            else if (!q.empty() && q.top() > course[0]) {
                time += course[0] - q.top();
                q.pop();
                q.push(course[0]);
            }
        }
        return q.size();
    }
};