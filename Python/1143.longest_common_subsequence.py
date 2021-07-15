class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        rows, cols = len(text1), len(text2)
        # Make a grid of 0's with len(text2) + 1 columns 
        # and len(text1) + 1 rows.
        dp_grid = [[0] * (cols+1) for _ in range(rows+1)]
        # Iterate up each column, starting from the last one.
        for row in range(rows):
            for col in range(cols):
                # If the corresponding characters for this cell are the same...
                if text1[row] == text2[col]:
                    dp_grid[row+1][col+1] = 1 + dp_grid[row][col]
                # Otherwise they must be different...
                else:
                    dp_grid[row+1][col+1] = max(dp_grid[row+1][col], dp_grid[row][col+1])
        # The original problem's answer is in dp_grid[0][0]. Return it.
        return dp_grid[rows][cols]

# Space optimization, with two rows instead of entire grid
class Solution2:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        rows, cols = len(text1), len(text2)
        # The previous and current column starts with all 0's and like 
        # before is 1 more than the length of the first word.
        previous = [0] * (cols + 1)
        current = [0] * (cols + 1)
        # Iterate up each column, starting from the last one.
        for row in range(rows):
            for col in range(cols):
                if text1[row] == text2[col]:
                    current[col+1] = 1 + previous[col]
                else:
                    current[col+1] = max(previous[col+1], current[col])
            # The current column becomes the previous one, and vice versa.
            previous, current = current, previous
        # The original problem's answer is in previous[0]. Return it.
        return previous[cols]