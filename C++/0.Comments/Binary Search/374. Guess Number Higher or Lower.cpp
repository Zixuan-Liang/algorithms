/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int pivot = left + (right - left) / 2;
            int hit = guess(pivot);
            if (hit == 0) {
                return pivot;
            }
            else if (hit == -1) {
                right = pivot - 1;
            }
            else {
                left = pivot + 1;
            }
        }
        return left;
    }
};