class Solution {
public:
    
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        if (n == 1) return 0;
        
        unordered_map<int, vector<int>> umap;
        for (int i = 0; i < arr.size(); i++) {
            umap[arr[i]].push_back(i);
        }
        
        queue<int> q;
        q.push(0);
        unordered_set<int> visited;
        visited.insert(0);
        int step = 0;
        
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                int index = q.front();
                q.pop();
                
                if (index == n - 1) return step;
                for (int next : umap[arr[index]]) {
                    if (visited.find(next) == visited.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
                umap[arr[index]] = {}; // 避免重复搜索
                for (int near : {index-1, index+1}) {
                    if (near >= 0 && near < n && visited.find(near) == visited.end()) {
                        q.push(near);
                        visited.insert(near);
                    }
                }
            }
            step++;
        }
        
        return step;
        
    }
};