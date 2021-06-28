#include <queue>

// 优先队列 Priority Queue
// 复杂度：服务器数量m，任务数量n
// 时间：O(mlogm) + O(nKlogK) (K为最大同时运行任务数)
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size();
        int n = tasks.size();
        
        // 最小堆保存可用服务器：{服务器ranking, 服务器索引}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;
        // 最小堆保存运行中服务器：{任务结束时间，服务器索引}
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> busyServers;
        vector<int> ans(n);
        
        for (int i = 0; i < m; ++i) { // 一开始将所有服务器进可用服务器队列
            freeServers.push({servers[i], i});
        }
        
        long time = 0; // 初始化当前时间
        for (long i = 0; i < n; ++i) { // 遍历所有任务
            time = max(i, time); // 如果当前任务的开始时间大于当前时间，将时间置为当前任务开始时间
            if (freeServers.empty() && busyServers.top().first > time) { // 如果无可用服务器，或者运行中的服务器最早结束时间比当前时间晚
                time = busyServers.top().first; // 则当前时间置为运行中的服务器最早结束时间
            }
            
            while (!busyServers.empty() && busyServers.top().first <= time) { // 将所有能在当前时间前结束运行的服务器放到空闲服务器队列中
                auto &info = busyServers.top();
                int index = info.second;
                freeServers.push({servers[index], index});
                busyServers.pop();
            }
            
            auto &info = freeServers.top(); // 将优先级最高的空闲服务器放进运行服务器队列
            busyServers.push({time + tasks[i], info.second});
            ans[i] = info.second; // 将该服务器的索引保存至ans
            freeServers.pop();
        }
        
        return ans;
    } 
};