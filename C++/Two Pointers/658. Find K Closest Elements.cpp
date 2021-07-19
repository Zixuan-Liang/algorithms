class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto lb = lower_bound(arr.begin(), arr.end(), x);
        int j = lb - arr.begin();
        int i = j - 1;
        while (j - i - 1 < k) {
            if (i == -1) {
                j++;
            }
            else if (j == arr.size() || abs(arr[i]-x) <= abs(arr[j]-x)) {
                i--;
            }
            else {
                j++;
            }
        }
        return vector<int>(arr.begin()+i+1, arr.begin()+j);
    }
};