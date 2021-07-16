/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int res = INT_MAX;
        vector<int> dim = binaryMatrix.dimensions();
        int rows = dim[0];
        int cols = dim[1];
        
        for (int i = 0; i < rows; i++){
            int left = 0;
            int right = cols - 1;
            int mid;
            while (left < right){
                mid = (left + right) / 2;
                if (binaryMatrix.get(i, mid) == 1) right = mid;
                else left = mid + 1;
            }
            if (binaryMatrix.get(i, left) == 1) res = min(res, left);
        }
        
        if (res == INT_MAX) return -1;
        else return res;
    }
};