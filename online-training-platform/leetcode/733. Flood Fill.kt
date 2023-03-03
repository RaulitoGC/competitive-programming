class Solution {

    val dx = mutableListOf(1, 0, -1, 0)
    val dy = mutableListOf(0, 1, 0, -1)

    private fun isValidPosition(x: Int, n: Int, y: Int, m: Int) : Boolean {
        return x < n && x >= 0 && y < m && y >= 0
    }

    fun floodFill(image: Array<IntArray>, sr: Int, sc: Int, color: Int): Array<IntArray> {
        val n = image.size; val m = image[0].size
        val visited = Array<BooleanArray>(n){
            BooleanArray(m){false}
        }

        val queue = ArrayDeque<Pair<Int, Int>>()
        val startingColor = image[sr][sc]
        queue.addLast(Pair(sr,sc))
        visited[sr][sc] = true

        while(queue.isNotEmpty()) {
            val size = queue.size

            repeat(size) {
                val current = queue.peekFirst()
                queue.removeFirst()
                image[current.first][current.second] = color 
                for(i in 0 until 4) {
                    val x = current.first + dx[i]
                    val y = current.second + dy[i]

                    if(isValidPosition(x, n, y, m) && startingColor == image[x][y] && visited[x][y].not()) {
                        visited[x][y] = true
                        queue.addLast(Pair(x,y))
                    }
                }
            }
        }

        return image
    }
}