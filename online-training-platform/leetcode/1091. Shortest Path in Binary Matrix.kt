class Solution {

    val dx = listOf(-1, 0, 1, 0, 1, -1, -1, 1)
    val dy = listOf(0, -1, 0, 1, 1, -1, 1, -1)

    private fun isValid(i: Int, rows: Int, j : Int,  cols: Int): Boolean {
        return 0 <= i && i < rows && 0 <= j && j < cols
    }

    fun shortestPathBinaryMatrix(grid: Array<IntArray>): Int {
        val rows = grid.size
        val cols = grid[0].size

        if(grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1){
            return -1
        }

        val queue = ArrayDeque<Pair<Int, Int>>()
        grid[0][0] = 1
        queue.addLast(Pair(0,0))

        while(queue.isNotEmpty()){
            val (cx, cy) = queue.peekFirst()
            queue.removeFirst()
            val distance = grid[cx][cy]

            if(cx == rows - 1 && cy == cols - 1){
                return distance
            }

            for(d in 0 until 8){
                val x = cx + dx[d]
                val y = cy + dy[d]
                if(isValid(x, rows, y, cols) && grid[x][y] == 0){
                    queue.addLast(Pair(x, y))
                    grid[x][y] = distance + 1
                }
            }
        }

        return -1
    }
}