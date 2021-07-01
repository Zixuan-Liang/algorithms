class Solution {
public:
    
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        const int numMasks = 1 << n;
        const int fullMask = numMasks - 1;
        // Encode course status into bit stream:
        // - Bit position 0 means the status of the first course, i.e. course 1,
        // - Bit position n-1 = the status of course n
        // - Value 1 at position i means course i+1 has not been selected.

        // dependOn[i]: Course i+1 depend on which courses?
        vector<int> dependOn(n);
        for (const auto & e: dependencies) {
          int course = e[1] - 1;
          int prerequisite = e[0] - 1;
          dependOn[course] |= 1 << prerequisite;
        }

        // preqForMask[mask]: Mask's all prerequisites
        vector<int> preqForMask(numMasks);
        for (int m = 1; m < numMasks; ++m)
          for (int c = 0; c < n; ++c)
            if (m & 1 << c)
              preqForMask[m] |= dependOn[c];

        // The minimal number of semesters of mask 'm', m = 1..fullMask.
        vector<int> dp(numMasks, n + 1);

        dp[fullMask] = 0;
        // Top-down, start from fullMask (all courses have not been selected)
        // O(3^n)
        for (int m = fullMask; m > 0; --m) {
          // haveTaken: bit value 1 means the course has been taken.
          //
          // m's 0 bits means the courses which have been taken. So flip m's bits to get
          // have taken course bits.
          //
          // haveTaken might be invalid, so its dp value will also be invalid (equal to n).
          int haveTaken = ~m;

          // Walk through all sub-masks of m
          for (int s = m; ; s = (s - 1) & m) {
            // We try to take some courses from m, but we can't take more than k.
            // e.g. m = 1110, k = 1, then sub-mask can not be: 1000, 0100, 0010, 0000 
            if (__builtin_popcount(m) - __builtin_popcount(s) > k) {
              if (s == 0)
                break;
              continue;
            }

            // The course we pick is: m ^ s, e.g. k = 2, m = 1110, s = 1000, so
            // pick = 0110.
            int pick = m ^ s;
            // If we have finished all prerequisities for pick, then we can use this 'pick'.
            if ((haveTaken & preqForMask[pick]) == preqForMask[pick])
              dp[s] = min(dp[s], dp[m] + 1);

            if (s == 0)
              break;
          }
        }
        return dp[0];
    }    

};