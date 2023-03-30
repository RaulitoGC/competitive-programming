class Solution {

    private fun searchLeft(nums: IntArray, target: Int): Int{
        var low = 0; var high = nums.size - 1
        while(low < high){
            val mid = low + (high - low) / 2
            if(target <= nums[mid]){
                high = mid
            } else {
                low = mid + 1
            }
        }

        return if(nums[low] == target) low else -1
    }

    private fun searchRight(nums: IntArray, target: Int): Int{
        var low = 0; var high = nums.size - 1
        while(low < high){
            val prevLow = low
            var flag = false
            val mid = (high + low) / 2
            if(target >= nums[mid]){
                flag = true
                low = mid
            } else {
                high = mid - 1
            }

            if(flag && prevLow == low){
                break
            }
        }

        return if(low + 1 < nums.size && nums[low + 1] == target) {
            low + 1
        } else if(nums[low] == target){
            low
        } else{
            -1
        }
    
    }

    fun searchRange(nums: IntArray, target: Int): IntArray {

        if(nums.isEmpty()){
            return intArrayOf(-1,-1)
        }
        val left = searchLeft(nums, target)
        val right = searchRight(nums, target)
        return if(left != -1 && right != -1) return intArrayOf(left, right) else intArrayOf(-1, -1)
    }
}