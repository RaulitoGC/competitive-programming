class Solution {
    
    val dx = mutableListOf<Int>(1, 0, -1, 0)
    val dy = mutableListOf<Int>(0, 1, 0, -1)
    
    fun Int.isValid(limit: Int) : Boolean {
        return this >= 0 && this < limit
    }
    
    fun Array<IntArray>.print() {
        this.forEach {
            it.forEach { num ->
                print("$num ")
            }
            println()
        }
        println()
    }
    
    fun orangesRotting(grid: Array<IntArray>): Int {
        val queue = ArrayDeque<Pair<Int,Int>>()
        
        var row = 0; var col = 0
        val rows = grid.size
        val cols = grid[0].size
        
        // println("$rows - $cols")
        
        while(row < rows){
            col = 0
            while(col < cols) {
                if(grid[row][col] == 2) {
                    queue.addLast(Pair(row,col))
                } 
                col += 1
            }
            row += 1
        }
        
        var result = 0
        var orangesReached = false
        
        while(queue.isNotEmpty()) {
            
            // println("size -> $queue.size")
            orangesReached = false
            repeat(queue.size) {
                val (x, y) = queue.first()
                queue.removeFirst()
                
                repeat(4) { idx ->
                    val nextX = x + dx[idx]
                    val nextY = y + dy[idx]

                    if(nextX.isValid(rows) && nextY.isValid(cols) && grid[nextX][nextY] == 1) {
                        queue.addLast(Pair(nextX, nextY))
                        grid[nextX][nextY] = 2
                        orangesReached = true
                    }
                }
                // grid.print()
            }
            
            // println("orangesReached -> $orangesReached")
            if(orangesReached) {
                result += 1    
            }
            
        }
        
        
        grid.forEach {
            it.forEach { num ->
                if ( num == 1){
                     return -1
                }
            }
            
        }
    
        
        return result
    }
}