class Solution {
    
    private fun getLeftGrid(grid: Array<CharArray>): Array<IntArray> {
        val result = Array<IntArray>(grid.size){
            IntArray(grid[0].size){
                0
            }
        }
        
        for(row in 0 until grid.size){
            var counter = 0
            for(column in 0 until grid[row].size) {
                if(grid[row][column] == 'E'){
                    counter += 1
                    result[row][column] = counter
                } else if(grid[row][column] == 'W'){
                    counter = 0
                }
            }
        }
        return result
    }
    
    private fun getRightGrid(grid: Array<CharArray>): Array<IntArray> {
        val result = Array<IntArray>(grid.size){
            IntArray(grid[0].size){
                0
            }
        }
        
        for(row in 0 until grid.size){
            var counter = 0
            for(column in grid[row].size - 1 downTo 0) {
                if(grid[row][column] == 'E'){
                    counter += 1
                    result[row][column] = counter
                } else if(grid[row][column] == 'W'){
                    counter = 0
                }
            }
        }
        
        return result
    }
    
    private fun getTopGrid(grid: Array<CharArray>): Array<IntArray> {
        val result = Array<IntArray>(grid.size){
            IntArray(grid[0].size){
                0
            }
        }
     
        for(column in 0 until grid[0].size) {
            var counter = 0
            for(row in 0 until grid.size){    
                if(grid[row][column] == 'E'){
                    counter += 1
                    result[row][column] = counter
                } else if(grid[row][column] == 'W'){
                    counter = 0
                }
            }
        }
        
        return result
    }
    
    private fun getBottomGrid(grid: Array<CharArray>): Array<IntArray> {
        val result = Array<IntArray>(grid.size){
            IntArray(grid[0].size){
                0
            }
        }
        
        for(column in 0 until grid[0].size) {
            var counter = 0
            for(row in grid.size - 1 downTo 0){    
                if(grid[row][column] == 'E'){
                    counter += 1
                    result[row][column] = counter
                } else if(grid[row][column] == 'W'){
                    counter = 0
                }
            }
        }
        return result
    }
    
    private fun getEmptyPositions(grid: Array<CharArray>): List<Pair<Int, Int>> {
        val result = mutableListOf<Pair<Int,Int>>()
        for(row in 0 until grid.size){
            for(colum in 0 until grid[row].size) {
                if(grid[row][colum] == '0'){
                    result.add(Pair(row, colum))
                }
            }
        }
        return result
    }
    
    fun maxKilledEnemies(grid: Array<CharArray>): Int {
        
        val rows = grid.size
        val columns = grid[0].size
        
        val left = getLeftGrid(grid)
        val right = getRightGrid(grid)
        val top = getTopGrid(grid)
        val bottom = getBottomGrid(grid)
        
        val emptyPositions = getEmptyPositions(grid)
        
        var result = 0
        
        emptyPositions.forEach{ position ->
            val row = position.first
            val colum = position.second
            
            //println("x = $x ,  y = $y")
            
            val topSoldiers = if(row - 1 < 0) 0 else top[row - 1][colum]
            val bottomSoldiers = if(row + 1 >= rows) 0 else bottom[row + 1][colum]
            val leftSoldiers = if(colum - 1 < 0) 0 else left[row][colum - 1]
            val rightSoldiers = if(colum + 1 >= columns) 0 else right[row][colum + 1]
            
            //println("top = $topSoldiers, bottom = $bottomSoldiers, left= $leftSoldiers, right = $rightSoldiers")
            
            result = max(
                result,
                topSoldiers + bottomSoldiers + leftSoldiers + rightSoldiers
            )
            
        }
        
        return result
    }
}