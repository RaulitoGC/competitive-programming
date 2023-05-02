class Solution {


    private fun setZeros(matrix: Array<IntArray>, startX: Int, startY: Int){
        val m = matrix.size
        val n = matrix[0].size

        for(i in 0 until m){
            matrix[i][startY] = 0
        }

        for(j in 0 until n){
            matrix[startX][j] = 0
        }
    }

    fun setZeroes(matrix: Array<IntArray>): Unit {
        
        val n = matrix.size
        val m = matrix[0].size
        val zeros = mutableListOf<Pair<Int, Int>>()

        for(i in 0 until n){
            for(j in 0 until m){
                if(matrix[i][j] == 0){
                    zeros.add(Pair(i, j))
                }
            }
        }

        zeros.forEach{ p ->
            setZeros(matrix, p.first, p.second)
        }
    }
}