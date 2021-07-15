class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> umap;
        for (int num : arr) {
            umap[num]++;
        }
        priority_queue<int> pq;
        for (auto [num, count] : umap) {
            pq.push(count);
        }
        int ans = 0;
        int removed = 0;
        while (removed < (arr.size()+1) / 2) {
            removed += pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};