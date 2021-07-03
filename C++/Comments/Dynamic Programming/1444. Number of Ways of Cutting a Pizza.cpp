// This is a DP problem. Let n, m denote the rows and columns of the matrix, mat denote the matrix, f[r][c][l] denote the number of ways to cut mat[r..m-1][c..n-1] into l pieces so that each piece has at least one apple on them, g[r][c] denote the number of apples on mat[r..m-1][c..n-1]. Because after cutting, we always have the down-right corner of the matrix left, so this setting is valid.

// For mat[r..m-1][c..n-1], we can cut the matrix in two directions in a number of ways, as long as the piece that is cut off has at least one apple on it. So

// f[r][c][l] = 
//     sum(f[i][c][l-1]) (i=r+1...m-1, g[r][c]-g[i][c]>0) +
//     sum(f[r][j][l-1]) (j=c+1...n-1, g[r][c]-g[r][j]>0)
// The time complexity is O(m * n * max(m, n) * k).

// Note: in the code, f[r][c][rest] means the way to cut mat[r..m-1][c..n-1] with rest cuts (and cutting into rest+1 pieces).

class Solution {
    int m, n;
    typedef long long int LL;
    LL P = 1e9 + 7;
    LL g[55][55];
    LL f[55][55][15];
    
    int dp(int r, int c, int rest) {
        if (f[r][c][rest] != -1) return f[r][c][rest];
        
        if (rest == 0) { // base case, 1刀不剩
            if (g[r][c] > 0) f[r][c][rest] = 1; // 有苹果，切法为1
            else f[r][c][rest] = 0; // 没苹果，切法为0
            return f[r][c][rest];
        }
        
        f[r][c][rest] = 0;
        
        // cut horizontally to [row, i-1] [i, m-1] 计算水平切法
        for (int i = r + 1; i < m; i++) {
            if (g[r][c] - g[i][c] > 0 && g[i][c] >= rest) { // 判断这一刀分割下去两边是否有足够的苹果
                f[r][c][rest] = (f[r][c][rest] + dp(i, c, rest - 1)) % P;
            }
        }
        
        // cut vertically to [col, j-1] [j, n-1] 计算垂直切法
        for (int j = c + 1; j < n; j++) {
            if (g[r][c] - g[r][j] > 0 && g[r][j] >= rest) // 判断这一刀分割下去两边是否有足够的苹果
                f[r][c][rest] = (f[r][c][rest] + dp(r, j, rest - 1)) % P;
        }
        
        return f[r][c][rest];
    }
    
public:
    int ways(vector<string>& pizza, int k) {
        m = pizza.size();
        n = pizza[0].size();
        
        // 预处理，计算g[i][j]：从[i,j]到右下角一共有多少个苹果
        memset(g, 0, sizeof(g));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                g[i][j] = g[i+1][j] + g[i][j+1] - g[i+1][j+1] + (pizza[i][j] == 'A'); // 利用到矩阵running sum的计算
            }
        }
        
        // 动态规划f[r][c][k]表示从[r,c]到右下角这一块披萨，切k刀有多少种方法
        memset(f, -1, sizeof(f));
        
        return dp(0, 0, k-1);
    }
};