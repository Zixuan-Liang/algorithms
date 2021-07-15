// Implementation 1
// A[low] <= A[i] <  A[high]
int binarySearch(vector<int> A, int x) {
    int n = A.size();
    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (A[mid] == x) {
            return mid;
        }
        else if (A[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return -1;
}

// Implementation 2
// A[low] <= A[i] <= A[high]
int binarySearch(vector<int> A, int x) {
    int n = A.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (A[mid] == x) {
            return mid;
        }
        else if (A[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}