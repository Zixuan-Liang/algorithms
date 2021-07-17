# from collections import defaultdict

class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        # draw examples to help find a pattern

        # Step through the grid in normal NM fashion. For every cell (r,c),
        # store number in the cell into dict with key (r+c) representing the
        # diagonal the number belongs to. The resulting dict thus has a
        # collection of diagonals in reverse order of desired, so for every key
        # flip the list of numbers and extend to result list.

        # O(MN) time and space

        rows, d = len(nums), {} # defaultdict(list)
        for r in range(rows):
            for c in range(len(nums[r])):
                diag = r + c
                if diag not in d:
                    d[diag] = []
                d[diag].append( nums[r][c] )

        res = []
        for i in range(len(d)):
            res.extend( reversed(d[i]) )
        return res