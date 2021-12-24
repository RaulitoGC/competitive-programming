class Solution {
    fun searchMatrix(matrix: Array<IntArray>, target: Int): Boolean {
        
        // Colum Bs
        var low = 0; var high = matrix.size - 1
        while(low < high){
            val mid = low + (high - low) / 2
            
            if(matrix[mid][0] < target) {
                low = mid + 1
            } else if(matrix[mid][0] > target) {
                high = mid - 1
            } else {
                return true
            }
        }
        
        if(matrix[low][0] > target && low > 0){
            low -= 1
        }
      
        var row = low
        low = 0
        high = matrix[row].size - 1
        
        while(low < high) {
            val mid = low + (high - low) / 2
            
            if(matrix[row][mid] < target) {
                low = mid + 1
            } else if (matrix[row][mid] > target) {
                high = mid -1
            } else {
                return true
            }
        }
        
        return matrix[row][low] == target
    }
}