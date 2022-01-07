class Solution {
    
    fun getLeftIdx(nums: IntArray, target: Int) : Int{
        var low = 0; var high = nums.size - 1
        while(low < high){
            //println("$low - $high")
            val mid = low + (high - low)/2
            //println("$low - $high - $mid")
            if(nums[mid] > target){
                high = mid - 1
            } else if(nums[mid] < target) {
                low = mid + 1
            } else {
                if(mid - 1 >= 0 && nums[mid - 1] == target){
                    high = mid
                }else{
                    return mid
                }
            }
        }
        
        return if(target == nums[low]) low else -1
    }
    
    fun getRightIdx(nums: IntArray, target: Int) : Int {
        var low = 0; var high = nums.size - 1
        while(low < high){
            val mid = low + (high - low)/2
            println("$low - $high - $mid")
            if(nums[mid] > target){
                high = mid - 1
            } else if(nums[mid] < target) {
                low = mid + 1
            } else {
                if(mid + 1 < nums.size && nums[mid + 1] == target){
                    low = mid + 1
                }else{
                    return mid
                }
            }
        }
        
        return if(target == nums[low]) low else -1
    }
    
    fun searchRange(nums: IntArray, target: Int): IntArray {
        if(nums.isEmpty()){
            return intArrayOf(-1, -1)
        }
        
        val leftIdx = getLeftIdx(nums, target)
        if(leftIdx == -1){
            return intArrayOf(-1, -1)
        }
        val rightIdx = getRightIdx(nums, target)
        
        return intArrayOf(leftIdx, rightIdx)
    }
}