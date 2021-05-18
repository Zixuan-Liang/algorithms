import java.util.ArrayDeque

class Solution {
    fun removeDuplicates(s: String, k: Int): String {
        var stack = ArrayDeque<Pair<Char, Int>>()
        var count = 1
        for (ch in s){
            count = if (stack.isEmpty() || stack.peek().first!=ch) 1 else stack.peek().second+1
            stack.push(Pair(ch, count))
            if (stack.peek().second >= k){
                for (i in 1..k) stack.pop()
            }
        }
        var res = "";
        for (ele in stack) res += ele.first
        return res.reversed()
    }
}