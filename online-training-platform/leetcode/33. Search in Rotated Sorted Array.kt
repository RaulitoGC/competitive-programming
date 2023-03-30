class Solution {
    fun search(nums: IntArray, target: Int): Int {
        var low = 0; var high = nums.size - 1
        while(low <= high){
            val mid = low + (high - low) / 2
            if (nums[mid] == target) return mid;
            else if (nums[mid] >= nums[low]) {
                if (target >= nums[low] && target < nums[mid]) high = mid - 1;
                else low = mid + 1;
            }
            else {
                if (target <= nums[high] && target > nums[mid]) low = mid + 1;
                else high = mid - 1;
            }
        }

        return -1
    }
}