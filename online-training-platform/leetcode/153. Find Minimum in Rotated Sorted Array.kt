class Solution {
    fun findMin(nums: IntArray): Int {

        if(nums.size == 1){
            return nums.first()
        }

        var low = 0; var high = nums.size - 1

        if(nums[high] > nums[0]){
            return nums[0]
        }

        while(low <= high){
            val mid = low + (high - low) / 2
            
            if(nums[mid] > nums[mid + 1]){
                return nums[mid + 1]
            }

            if(nums[mid - 1] > nums[mid]){
                return nums[mid]
            }

            if(nums[mid] > nums[0]){
                low = mid + 1
            } else {
                high = mid - 1
            }
        }

        return kotlin.math.min(nums[high], nums[low])
    }
}