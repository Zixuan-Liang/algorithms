class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        var memo : HashMap<Int, Int> = HashMap<Int, Int> ()
        for (i in 0..nums.size-1){
            var num = nums[i]
            if (memo.containsKey(num)) {
                return intArrayOf(memo.get(num)!!.toInt(), i)
            }
            memo.put(target - num, i)
        }
        return intArrayOf(-1, -1)
    }
}