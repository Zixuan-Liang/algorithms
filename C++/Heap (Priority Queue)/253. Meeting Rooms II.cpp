#include <queue>

// 优先队列 Priority Queue
// 复杂度：会议数量n，时间O(nlogn)，空间O(n)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> rooms; // 最小堆保存会议室变成空置的时间
        sort(intervals.begin(), intervals.end()); // 按照会议开始时间进行排序
        for (auto& interval : intervals) {
            if (rooms.empty() || rooms.top() > interval[0]) { // 如果无可用会议室，分配一个新会议室给当前会议，会议结束时间（新会议室将来可用时间）进堆
                rooms.push(interval[1]);
            }
            else { // 如果有空置会议室，出堆，将新的会议结束时间进堆
                rooms.pop();
                rooms.push(interval[1]);
            }
        }
        return rooms.size(); // 所有会议分配完，堆的大小就是所需会议室数量
    }
};