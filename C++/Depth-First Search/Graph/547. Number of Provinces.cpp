class Solution {
public:
    
    void search(int i, vector<int>& visited, vector<vector<int>>& isConnected) {
        visited[i] = 1;
        for (int j = 0; j < isConnected.size(); j++) {
            if (visited[j] == 0 && isConnected[i][j] == 1) {
                search(j, visited, isConnected);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                ans++;
                search(i, visited, isConnected);
            }
        }
        return ans;
    }
};