class Solution {

    fun dfs(board: Array<CharArray>, x: Int, y: Int){
        if(board[x][y] != 'O'){
            return
        }

        board[x][y] = 'E'

        if(x > 0){
            dfs(board, x - 1, y)
        }
        
        if ( x < board.size - 1){
            dfs(board, x + 1, y)
        } 
        
        if ( y > 0){
            dfs(board, x, y - 1)
        }

        if(y < board[0].size - 1) {
            dfs(board, x, y + 1)
        }
    }

    fun solve(board: Array<CharArray>): Unit {
        val rows = board.size
        val cols = board[0].size
        
        for(j in 0 until cols){
            //if(board[0][j] == 'O'){
                dfs(board, 0, j)
            //}

            //if(board[rows - 1][j] == 'O'){
                dfs(board, rows - 1, j)
            //}
        }

        for(i in 0 until rows){
            //if(board[i][0] == 'O'){
                dfs(board, i, 0)
            //}

            //if(board[i][cols - 1] == 'O'){
                dfs(board, i, cols - 1)
            //}
        }

        for(i in 0 until rows){
            for(j in 0 until cols){
                
                if(board[i][j] == 'O'){
                    board[i][j] = 'X'
                }

                if(board[i][j] == 'E'){
                    board[i][j] = 'O'
                } 
            }
        }

    }
}