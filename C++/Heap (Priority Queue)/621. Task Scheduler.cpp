class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskCount;
        for (char task : tasks) {
            taskCount[task]++;
        }
        priority_queue<pair<int, char>> taskQueue;
        for (auto [task, count] : taskCount) {
            taskQueue.push({count, task});
        }
        int allTime = 0;
        int cycle = n + 1;
        while (!taskQueue.empty()) {
            vector<pair<int, char>> currCycle;
            int time = 0;
            for (int i = 0; i < cycle; i++) {
                if (!taskQueue.empty()) {
                    currCycle.push_back(taskQueue.top());
                    taskQueue.pop();
                    time++;
                }
            }
            for (auto [count, task] : currCycle) {
                if (count - 1 > 0) {
                    taskQueue.push({count - 1, task});
                }
            }
            allTime += taskQueue.empty() ? time : cycle;
        }
        return allTime;
    }
};