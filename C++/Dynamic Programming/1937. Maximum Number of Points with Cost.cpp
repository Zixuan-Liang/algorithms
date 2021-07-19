#define ll long long

class Solution {
public:
    long long maxPoints(vector<vector<int>>& P) {
      ll n = P.size(), m = P[0].size();

      vector<ll> prev(m); 
      for(int i=0; i<m; ++i) prev[i] = P[0][i];
      
      for(int i = 1; i < n; ++i){
        vector<ll> curr(m, 0);
        auto right = curr, left = curr;
        
        // traverse left to right
        left[0] = prev[0];
        for(int j=1; j<m; ++j) {
          left[j] = max(left[j-1]-1, prev[j]);
        }
        
        // traverse right to left
        right[m-1] = prev[m-1];
        for(int j=m-2; j>=0; --j) {
          right[j] = max(right[j+1]-1, prev[j]);
        }
        
        // update current with max from left, right + value
        for(int j=0; j<m; ++j){
          curr[j] = P[i][j] + max(left[j], right[j]);
        }
        
        prev = curr;
      }
      
      ll ans = prev[0];
      for(auto &i: prev) ans = max(ans, i);
      return ans;
    }
};