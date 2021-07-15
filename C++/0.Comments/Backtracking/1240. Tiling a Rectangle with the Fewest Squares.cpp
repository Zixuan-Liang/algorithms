class Solution {
public:
    int covered[14][14];
    int ans = 14*14;
    int tilingRectangle(int n, int m) {
        if(n == m) return 1;
        memset(covered, 0, sizeof(covered));
        int cur = 0;
        dfs(n, m, cur);
        return ans;
    }
    void dfs(int n, int m, int cur) {
        if(cur >= ans) return;
        bool full = true;
        int row, col;
        for(int i = 0; i < n && full; i++) {
            for(int j = 0; j < m && full; j++) {
                if(covered[i][j] == 0) {
                    full = false;
                    row = i; col = j;
                }
            }
        }
        if(full)
            return (void)(ans = min(ans,cur));

        for(int len = min(n-row, m-col); len >= 1; len--) {
            bool isEmpty = true;

            for(int i = row; i < row+len && isEmpty; i++)
                for(int j = col; j < col+len && isEmpty; j++)
                    if(covered[i][j] == 1) isEmpty = false;

            if(!isEmpty) continue;

            for(int i = row; i < row+len; i++)
                for(int j = col; j < col+len; j++) 
                    covered[i][j] = 1;

            dfs(n, m, cur+1);
            
            for(int i = row; i < row+len; i++)
                for(int j = col; j < col+len; j++)
                    covered[i][j] = 0;
        }
    }
};