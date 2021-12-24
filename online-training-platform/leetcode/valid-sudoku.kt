class Solution {
    fun isValidSudoku(board: Array<CharArray>): Boolean {
        
        // Row
        val row = HashSet<Char>()
        for(r in 0 until 9){
            row.clear()
            for(c in 0 until 9){
                if(board[r][c] == '.') continue
                if( row.contains(board[r][c])){
                    return false
                }
                row.add(board[r][c])
            }
        }
        
        // Colum
        val colum = HashSet<Char>()
        for(c in 0 until 9){
            colum.clear()
            for(r in 0 until 9){
                if(board[r][c] == '.') continue
                if(colum.contains(board[r][c])){
                    return false
                }
                colum.add(board[r][c])
            }
        }
        
        
        // Square
        val box = HashSet<Char>()
        for(r in 0 until 9 step 3){
            for(c in 0 until 9 step 3){
                box.clear()
                for(i in r until r + 3){
                    for(j in c until c + 3){
                        if(board[i][j] == '.') continue
                        if(box.contains(board[i][j])){
                            return false
                        }
                        box.add(board[i][j])
                    }
                }
            }
        }
        
        return true
    }
}