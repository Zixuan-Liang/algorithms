import java.util.*;
// import javafx.util.Pair;

class Solution {
    public String removeDuplicates(String s, int k) {
        ArrayDeque<Pair<Character, Integer>> stack = new ArrayDeque<Pair<Character, Integer>>();
        int count = 1;
        for(int i = 0, n = s.length() ; i < n ; i++) { 
            char c = s.charAt(i);
            count = (stack.isEmpty() || stack.getFirst().getKey()!=c)? 1 : stack.getFirst().getValue()+1;
            stack.addFirst(new Pair<Character, Integer>(c, count));
            if (stack.getFirst().getValue() >= k){
                for (int j = 0; j < k; j++) stack.removeFirst();
            }
        }
        StringBuilder res = new StringBuilder();
        while (!stack.isEmpty()){
            res.append(stack.removeFirst().getKey());
        }
        res.reverse();
        return res.toString();
    }
}