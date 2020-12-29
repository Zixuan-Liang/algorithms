class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        
        # Make a grid of 0's with len(text2) + 1 columns 
        # and len(text1) + 1 rows.
        dp_grid = [[0] * (len(text2) + 1) for _ in range(len(text1) + 1)]
        
        # Iterate up each column, starting from the last one.
        
        for row in reversed(range(len(text1))):
            for col in reversed(range(len(text2))):
                # If the corresponding characters for this cell are the same...
                if text1[row] == text2[col]:
                    dp_grid[row][col] = 1 + dp_grid[row + 1][col + 1]
                # Otherwise they must be different...
                else:
                    dp_grid[row][col] = max(dp_grid[row + 1][col], dp_grid[row][col + 1])
        
        # The original problem's answer is in dp_grid[0][0]. Return it.
        return dp_grid[0][0]

# Space optimization, with two rows instead of entire grid
class Solution2:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # The previous and current column starts with all 0's and like 
        # before is 1 more than the length of the first word.
        previous = [0] * (len(text2) + 1)
        current = [0] * (len(text2) + 1)
        # Iterate up each column, starting from the last one.
        for row in reversed(range(len(text1))):
            for col in reversed(range(len(text2))):
                if text1[row] == text2[col]:
                    current[col] = 1 + previous[col + 1]
                else:
                    current[col] = max(previous[col], current[col + 1])
            # The current column becomes the previous one, and vice versa.
            previous, current = current, previous
        
        # The original problem's answer is in previous[0]. Return it.
        return previous[0]