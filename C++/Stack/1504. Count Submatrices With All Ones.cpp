class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int> > row(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j == 0) {
                    row[i][j] = mat[i][j];
                } else if (mat[i][j]) {
                    row[i][j] = row[i][j - 1] + 1;
                }
                else {
                    row[i][j] = 0;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < m; ++j) { 
            int i = 0; 
            stack<pair<int, int> > Q; 
            int sum = 0; 
            while (i <= n - 1) { 
                int height = 1; 
                while (!Q.empty() && Q.top().first > row[i][j]) {
                  	// 弹出的时候要减去多于的答案
                    sum -= Q.top().second * (Q.top().first - row[i][j]); 
                    height += Q.top().second; 
                    Q.pop(); 
                } 
                sum += row[i][j]; 
                ans += sum; 
                Q.push({ row[i][j], height }); 
                i++; 
            } 
        } 
        return ans;
    }
};