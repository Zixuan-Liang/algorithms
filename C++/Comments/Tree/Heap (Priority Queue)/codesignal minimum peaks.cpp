#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

// min heap, O(nlogn)
vector<int> findMinPeaks(vector<int>& nums) {
    int n = nums.size();
    nums.push_back(INT_MIN);
    vector<int> ans;
    vector<int> prev(n+1); prev[0] = n;
    for (int i = 1; i < n+1; i++) prev[i] = i - 1;
    vector<int> next(n+1); next[n] = 0;
    for (int i = 0; i <= n-1; i++) next[i] = i + 1;
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[prev[i]] && nums[i] > nums[next[i]]) {
            pq.push({nums[i], i});
        }
    }
    while (!pq.empty()) {
        vector<int> peak = pq.top();
        pq.pop();
        ans.push_back(peak[0]);
        int j = prev[peak[1]], k = next[peak[1]];
        prev[k] = j;
        next[j] = k;
        if (nums[j] > nums[prev[j]] && nums[j] > nums[next[j]]) {
            pq.push({nums[j], j});
        }
        if (nums[k] > nums[prev[k]] && nums[k] > nums[next[k]]) {
            pq.push({nums[k], k});
        }
    }
    return ans;
}

// O(n^2)
vector<int> findMinPeaks2(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int minPeak = INT_MAX;
        int index = -1;
        int m = nums.size();
        for (int j = 0; j < m; j++) {
            if (j == 0 && j + 1 < m) {
                if (nums[j] > nums[j + 1] && minPeak > nums[j]) {
                    minPeak = nums[j];
                    index = j;
                }
            }
            else if (j == m - 1 && j - 1 >= 0) {
                if (nums[j] > nums[j - 1] && minPeak > nums[j]) {
                    minPeak = nums[j];
                    index = j;
                }
            }
            else if (m == 1) {
                minPeak = nums[j];
                index = j;
            }
            else if (nums[j] > nums[j - 1] && nums[j] > nums[j + 1] && minPeak > nums[j]) {
                minPeak = nums[j];
                index = j;
            }
        }
        nums.erase(nums.begin() + index);
        ans.push_back(minPeak);
    }
    return ans;
}

int main() {
//    vector<int> test = {1, 9, 7, 8, 2, 6};
    vector<int> test = {2,7,8,5,1,6,3,9,4};
    vector<int> ans1 = findMinPeaks(test);
    vector<int> ans2 = findMinPeaks2(test);
    for (int i = 0; i < ans1.size(); i++) {
        if (ans1[i] != ans2[i]) {
            cout << "Wrong" << endl;
        }
        else {
            cout << ans1[i] << endl ;
        }
    }
    return 0;
}
