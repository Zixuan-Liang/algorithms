class Solution {
public:

    void duplicateZeros(vector<int>& A) {
        int n = A.size(), zeros = count(A.begin(), A.end(), 0);
        int i = n - 1;
        int write = n + zeros - 1;
        while (i >= 0 && write >= 0) {
            if (A[i] != 0) { // Non-zero, just write it in
                if (write < n) A[write] = A[i];
            }
            else { // Zero found, write it in twice if we can
                if (write < n) A[write] = A[i];
                write--;
                if (write < n) A[write] = A[i];
            }
            i--;
            write--;
        }
    }
    
};