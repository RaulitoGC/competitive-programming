class Solution {
    
  private val dx = mutableListOf(-1, 0, 1, 0)
  private val dy = mutableListOf(0, -1, 0, 1)
  
  private fun isValidPosition(x: Int, n: Int, y: Int, m: Int): Boolean {
      return x < n && x >= 0 && y < m && y >= 0
  }

  private fun markIsland(startX: Int, startY: Int, grid: Array<CharArray>){
      
      val queue = ArrayDeque<Pair<Int, Int>>()
      val n = grid.size
      val m = grid[0].size
      queue.addLast(Pair(startX, startY))
      grid[startX][startY] = '0'

      while(queue.isNotEmpty()) {
          val size = queue.size
          repeat(size) {
              val current = queue.peekFirst()
              queue.removeFirst()

              for(i in 0 until 4) {
                  val x = current.first + dx[i]
                  val y = current.second + dy[i]
                  if(isValidPosition(x, n, y, m) && grid[x][y] == '1'){
                      grid[x][y] = '0'
                      queue.addLast(Pair(x,y))
                  }
              }
          }
      }

      
  }

  
  fun numIslands(grid: Array<CharArray>): Int {

      var islands = 0
      grid.forEachIndexed{ i, row ->
          row.forEachIndexed{ j, col ->            
              if(grid[i][j] == '1') {
                  markIsland(i, j, grid)
                  islands += 1
              }
          }
      }


      return islands    
  }
}