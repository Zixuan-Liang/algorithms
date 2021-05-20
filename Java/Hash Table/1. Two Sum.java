import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> memo = new HashMap<>();
        for (int i = 0, n = nums.length; i < n; i++){
            int num = nums[i];
            if (memo.containsKey(num)) return new int[]{memo.get(num), i};
            memo.put(target - num, i);
        }
        return new int[2];
    }
}