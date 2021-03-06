# Define num: the current number in arr1 we are visiting.
# Define left: the number left to the num in arr1.
# Define bigger: the least one of those numbers in arr2 that are strictly greater than left.

# eg:

# arr1 = {3, 4, 7, 5, 8}
# sorted arr2 = {1, 2, 6, 9, 10}
# if num=5, then left=7, bigger=9.

# Preparation: sort arr2 and use binary serarch
# For a given num, how to find bigger efficiently? We can first sort arr2, then binary-search left in arr2 and get the least number strictly greater than left, in O(lg(arr2.length)) time.

# Why/when do we want to find bigger? Whenever we know we have to replace the num because left >= num, we have perhaps multiple choices to choose from arr2. We will anyway cost one replacement. So choosing the least possible one won't be worse than choosing the other possible numbers from arr2. ("worse" in terms of the total number of replacements.)

# Brute force
# The brute force solution will be using backtracking algorithm.

# Scanning arr1 from left to right, visiting num. Suppose when we've scanned to num, all numbers left to num are already strictly increasing. Now, speaking of num, there are two possible cases can happen: left < num :), or left >= num which breaks the monotonic condition :(.

# Case 1. left < num
# We know left < num satisfies the monotonic constraint. But don't be happey too early. Our goal is not to create an arbitrary array that satisfies the monotonic constraint. Our goal is to use the least number of replacements to achieve that. So we still have two branches for the next step of search:

# Condition 1: Do not replace num. Scan rightward to visit the next number in arr1 and continue.
# Condition 2: Replace num with bigger. Scan rightward to visit the next number in arr1 and continue.
# Each search of the two respectively gives us the least number of replacements needed to make all numbers right to num monotonic. Define: res1 be the least number of replacements needed for condition 1, and res2 for condition 2. Then we know min(res1, res2 + 1). min(res1, res2 + 1) is the least number of replacements needed to make num and numbers right to num monotonic. The +1 is because condition 2 replaces num with bigger, and that +1 a replacement.

# When both condition 1 & 2 can't make the rest of numbers monotonic, then we say "sorry, i can't make num and the rest numbers monotonic." So we have to backtrack.

# Case 2. left >= num
# Then we have to replace num with bigger. This is basically the condition 2 above.

# With the above analysis, we can come up with a brute-force solution that is doing backtracking. But the time complexity is too high. Each visit of a num may potentionally cause two branches of subqueries.

# Improve by memoization
# We may have to do the query multiple times: "when I am visiting num, observing left, what is the least number of replacements needed to make num and all numbers right to num monotonic?" Let's cache the query result. In the following code, the attempt function is doing the query. index implys num; must_strictly_bigger_than is left and implies bigger. ("implies" means you need to do some trivial computation to get what you want.)

# For those are not familiar with Python3, @functools.lru_cache(None) does the cache trick. It caches attempt(index, must_strictly_bigger_than)'s result, and will return the result of attempt immediately if it's been cacluated before for the given input.

import bisect, functools
class Solution:
    def makeArrayIncreasing(self, arr1: List[int], arr2: List[int]) -> int:
        arr2 = sorted(set(arr2))
        
        def getSlightlyStrightlyBigger(n):
            index = bisect.bisect_right(arr2, n)
            if index == len(arr2):
                return None
            return arr2[index]
        
        @functools.lru_cache(None)
        def attempt(index, must_strictly_bigger_than):
            if index == len(arr1):
                return 0
            # res1: don't replace arr1[index]
            if must_strictly_bigger_than < arr1[index]:
                res1 = attempt(index + 1, arr1[index])
            else:
                res1 = float('inf')
            bigger = getSlightlyStrightlyBigger(must_strictly_bigger_than)
            # res2: replace arr1[index]
            if bigger is None:
                res2 = float('inf')
            else:
                res2 = attempt(index + 1, bigger)
            return min(res1, res2 + 1)
                
        res = attempt(0, float('-inf'))
        return res if res != float('inf') else -1

# Time & space complexity
# Define n = max(arr1.length, arr2.length)

# When calling attempt(index, left), consider the possible arguments. There are arr1.length many choices for index, and at most arr1.length many choices for left for each given index. So there will be at most n * n many different values for the pair (index, left).

# So the space complexity is O(n^2).

# Each call of attempt may trigger a binary search over arr2. So the total overall time complexity is O(n^2 log n).