// Implementation 1
// A[low] <= A[i] <  A[high]
int binarySearch(vector<int> A, int x) {
    int n = A.size();
    int low = 0, high = n; 
    while (low < high) { // 循环不变性：如果答案存在，则位于区间[low, high)
        int mid = low + (high - low) / 2;
        if (A[mid] == x) { // 找到答案
            return mid;
        }
        else if (A[mid] < x) { // 保持循环不变性：如果答案存在，则位于区间[low, high)
            low = mid + 1;
        }
        else { // 保持循环不变性：如果答案存在，则位于区间[low, high)
            high = mid;
        }
    }
    return -1; // 循环被打破，此时low=high，区间长度为0，答案不存在
}

// Implementation 2
// A[low] <= A[i] <= A[high]
int binarySearch(vector<int> A, int x) {
    int n = A.size();
    int low = 0, high = n - 1; 
    while (low <= high) { // 循环不变性：如果答案存在，则位于区间[low, high]
        int mid = low + (high - low) / 2;
        if (A[mid] == x) { // 找到答案
            return mid;
        }
        else if (A[mid] < x) { // 保持循环不变性：如果答案存在，则位于区间[low, high]
            low = mid + 1;
        }
        else { // 保持循环不变性：如果答案存在，则位于区间[low, high]
            high = mid - 1;
        }
    }
    return -1; // 循环被打破，此时low>high，区间长度为0，答案不存在
}