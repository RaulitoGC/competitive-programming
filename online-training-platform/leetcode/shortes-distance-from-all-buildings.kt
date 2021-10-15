class Solution {
  
    val dx = listOf(0, 1, 0, -1)
    val dy = listOf(-1, 0, 1, 0)
    
    fun isValidPosition(x: Int, n: Int, y: Int, m: Int) : Boolean{
      return x >= 0 && x < n && y >= 0 && y < m
    }
  
    fun bfs(startRow: Int, startColum: Int, grid: Array<IntArray>, totalHouses : Int): Int {
      
      val n = grid.size; val m = grid[0].size
      val visited = Array(n) { BooleanArray(m) { false }}
      
      val queue = ArrayDeque<Pair<Int, Int>>()
      var level = 0; var distance = 0; var housesReached = 0
      val startPosition = Pair(startRow, startColum)
      queue.addLast(startPosition)
      visited[startRow][startColum] = true
      
      while(!queue.isEmpty()) {
        val size = queue.size
        for(i in 0 until size) {
          val currentPosition = queue.peekFirst()
          queue.removeFirst()
          
          if(grid[currentPosition.first][currentPosition.second] == 1) {
            distance += level
            housesReached++
            continue
          }
          
          for(idx in 0 until 4) {
            val x = currentPosition.first + dx[idx]
            val y = currentPosition.second + dy[idx]
            
            if(isValidPosition(x, n, y, m) && grid[x][y] != 2 && !visited[x][y]) {
              queue.addLast(Pair(x,y))
              visited[x][y] = true
            }
          }
        }
        level++
      }
      
      if(housesReached != totalHouses) {
        for(row in 0 until n) {
          for(colum in 0 until m) {
            if(grid[row][colum] == 0 && visited[row][colum]) {
              grid[row][colum] = 2
            }
          }
        }
        
        return Int.MAX_VALUE
      }
      
      
      return distance
    }
  
    fun shortestDistance(grid: Array<IntArray>): Int {
      
      val n = grid.size; val m = grid[0].size
      var totalHouses = 0
      
      for(row in 0 until n) {
        for(colum in 0 until m) {
          if(grid[row][colum] == 1) {
            totalHouses++
          }
        }
      }
      
      var minDistance = Int.MAX_VALUE
      
      for(row in 0 until n) {
        for(colum in 0 until m) {
          if(grid[row][colum] == 0) {
            minDistance = Math.min(minDistance, bfs(row, colum, grid, totalHouses))  
          }
        }
      }
      
      if(minDistance == Int.MAX_VALUE) {
        return -1
      }
      
      return minDistance
    }
}