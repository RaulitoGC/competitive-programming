class Solution {
    fun searchMatrix(matrix: Array<IntArray>, target: Int): Boolean {
        var rLow = 0; var rHigh = matrix.size - 1
        while(rLow < rHigh){
            val rMid = rLow + (rHigh - rLow) / 2
            if(matrix[rMid][0] < target){
                rLow = rMid + 1
            } else if(matrix[rMid][0] > target) {
                rHigh = rMid - 1
            } else{
                return true
            }
        }

        //println(rLow)
        if(rLow + 1 < matrix.size && matrix[rLow + 1][0] <= target){
            rLow += 1
        } else if(rLow - 1 >= 0 && matrix[rLow][0] > target){
            rLow -= 1
        }
        //println(rLow)
        
        var cLow = 0; var cHigh = matrix[rLow].size - 1
        while(cLow < cHigh){
            val cMid = cLow + (cHigh - cLow) / 2
            if(matrix[rLow][cMid] < target) {
                cLow = cMid + 1
            } else if(matrix[rLow][cMid] > target){
                cHigh = cMid - 1
            } else {
                return true
            }
        }

        return matrix[rLow][cLow] == target

    }
}