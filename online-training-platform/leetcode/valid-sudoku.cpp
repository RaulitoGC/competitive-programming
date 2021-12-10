class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // Rows
        for(int r = 0 ; r < 9 ; r++) {
            set<char> numbers;
            for(int c = 0 ; c < 9 ; c++) {
                
                if(board[r][c] == '.'){
                    continue;
                }
                
                if(numbers.find(board[r][c]) != numbers.end()) {
                    return false;
                }
                numbers.insert(board[r][c]);
            }
        }
        
        // Colum
        for(int c = 0 ; c < 9 ; c++) {
            set<char> numbers;
            for(int r = 0 ; r < 9 ; r++) {
                
                if(board[r][c] == '.'){
                    continue;
                }
                
                if(numbers.find(board[r][c]) != numbers.end()) {
                    return false;
                }
                numbers.insert(board[r][c]);
            }
        }
        
        // Square
        for(int c = 0 ; c < 9 ; c += 3) {
            for(int r = 0 ; r < 9 ; r += 3) {
                
                set<char> numbers;
                for(int i = r ; i < r + 3 ; i++) {
                    for(int j = c ; j < c + 3 ; j++) {
                        if(board[i][j] == '.'){
                            continue;
                        }

                        if(numbers.find(board[i][j]) != numbers.end()) {
                            return false;
                        }
                        numbers.insert(board[i][j]);        
                    }
                }   
            }
        }
        return true;
    }
};