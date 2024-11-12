class Solution {
    
    private fun getDiagonalSorted(
        startX: Int,
        startY: Int,
        mat: Array<IntArray>
    ): List<Int> {
        var x = startX
        var y = startY
        val result = mutableListOf<Int>()
        
        while(x < mat.size && y < mat[0].size ) {
            result.add(mat[x][y])
            x += 1
            y += 1
        }
        
        return result.sorted()
    }
    
    fun diagonalSort(mat: Array<IntArray>): Array<IntArray> {
        
        var row = mat.size - 1
        var col = 0
        
        // Traverse bottom to Top
        while(row >= 0) {
            
            val diagonalSorted = getDiagonalSorted(row, col, mat)
            
            var x = row; var y = col; var idx = 0
            
            while(idx < diagonalSorted.size ) {
                mat[x][y] = diagonalSorted[idx]
                idx += 1
                x += 1
                y += 1
            }
            
            row -= 1
        }
        
        row = 0
        col += 1
        // Traverse Left to Right
        while(col < mat[0].size) {
            
            val diagonalSorted = getDiagonalSorted(row, col, mat)
            
            var x = row; var y = col; var idx = 0
            
            while(idx < diagonalSorted.size ) {
                mat[x][y] = diagonalSorted[idx]
                idx += 1
                x += 1
                y += 1
            }
            
            col += 1
        }
        
        return mat
    }
}