// This is a DP problem. Let n, m denote the rows and columns of the matrix, mat denote the matrix, f[r][c][l] denote the number of ways to cut mat[r..n-1][c..m-1] into l pieces so that each piece has at least one apple on them, g[r][c] denote the number of apples on mat[r..n-1][c..m-1]. Because after cutting, we always have the down-right corner of the matrix left, so this setting is valid.

// For mat[r..n-1][c..m-1], we can cut the matrix in two directions in a number of ways, as long as the piece that is cut off has at least one apple on it. So

// f[r][c][l] = 
//     sum(f[i][c][l-1]) (i=r+1...n-1, g[r][c]-g[i][c]>0) +
//     sum(f[r][j][l-1]) (j=c+1...m-1, g[r][c]-g[r][j]>0)
// The time complexity is O(n * m * max(n, m) * k).

// Note: in the code, f[r][c][rest] means the way to cut mat[r..n-1][c..m-1] with rest cuts (and cutting into rest+1 pieces).

class Solution {
    int n, m;
    vector<string> pizza;
    typedef long long int LL;
    LL P = 1e9 + 7;
    LL g[55][55];
    LL f[55][55][15];
    
    int dp(int r, int c, int rest) {
        if (f[r][c][rest] != -1) return f[r][c][rest];
        
        if (rest == 0) {
            if (g[r][c] > 0) f[r][c][rest] = 1;
            else f[r][c][rest] = 0;
            return f[r][c][rest];
        }
        
        f[r][c][rest] = 0;
        
        // cut horizontally to [row, i-1] [i, n-1]
        for (int i = r + 1; i < n; i++) {
            if (g[r][c] - g[i][c] > 0 && g[i][c] >= rest) {
                f[r][c][rest] = (f[r][c][rest] + dp(i, c, rest - 1)) % P;
            }
        }
        
        // cut vertically to [col, j-1] [j, m-1]
        for (int j = c + 1; j < m; j++) {
            if (g[r][c] - g[r][j] > 0 && g[r][j] >= rest)
                f[r][c][rest] = (f[r][c][rest] + dp(r, j, rest - 1)) % P;
        }
        
        return f[r][c][rest];
    }
    
public:
    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza[0].length();
        this->pizza = pizza;
        
        memset(g, 0, sizeof(g));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                g[i][j] = g[i+1][j] + g[i][j+1] - g[i+1][j+1] + (pizza[i][j] == 'A');
            }
        }
        
        memset(f, -1, sizeof(f));
        
        return dp(0, 0, k-1);
    }
};