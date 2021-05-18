import java.util.Stack;
// import javafx.util.Pair;

class Solution {
    public String removeDuplicates(String s, int k) {
        Stack<Pair<Character, Integer>> stack = new Stack<Pair<Character, Integer>>();
        int count = 1;
        for(int i = 0, n = s.length() ; i < n ; i++) { 
            char c = s.charAt(i);
            count = (stack.isEmpty() || stack.peek().getKey()!=c)? 1 : stack.peek().getValue()+1;
            stack.push(new Pair<Character, Integer>(c, count));
            if (stack.peek().getValue() >= k){
                for (int j = 0; j < k; j++) stack.pop();
            }
        }
        StringBuilder res = new StringBuilder();
        while (!stack.isEmpty()){
            res.append(stack.pop().getKey());
        }
        res.reverse();
        return res.toString();
    }
}