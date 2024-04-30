class Solution {
    fun moveZeroes(nums: IntArray): Unit {
        
        var zeroIdx = nums.indexOfFirst{
            it == 0
        }
        var nonZeroIdx = nums.indexOfFirst {
            it != 0
        }

        if(zeroIdx == -1 || nonZeroIdx == -1) {
            return 
        }


        while(true){
            if( zeroIdx < nonZeroIdx) {
                nums[zeroIdx] = nums[nonZeroIdx].also{
                    nums[nonZeroIdx] = nums[zeroIdx]
                }
                zeroIdx += 1   
            }
            nonZeroIdx += 1
            
            while(zeroIdx < nums.size && nums[zeroIdx] != 0) {
                zeroIdx += 1
            } 

            while(nonZeroIdx < nums.size && nums[nonZeroIdx] == 0) {
                nonZeroIdx += 1
            }

            if(zeroIdx >= nums.size || nonZeroIdx >= nums.size) {
                return
            }
        }
    }
}