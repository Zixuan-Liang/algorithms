class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto upper = upper_bound(arr.begin(), arr.end(), x);
        int j = upper - arr.begin();
        int i = j - 1;
        deque<int> dq;
        while (i >= 0 && j < arr.size() && dq.size() < k) {
            int di = abs(arr[i] - x), dj = abs(arr[j] - x);
            if ( di <= dj )
                dq.push_front(arr[i--]);
            else
                dq.push_back(arr[j++]);
        }
        while (dq.size() < k) {
            if (i >= 0)
                dq.push_front(arr[i--]);
            else 
                dq.push_back(arr[j++]);
        }
        return vector<int>(dq.begin(), dq.end());
    }
};