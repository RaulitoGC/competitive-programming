class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int r = matrix.size();
        int c = matrix[0].size();
        int dp[r+1][c+1];
        
        dp[0][0] = 0;
      
        for(int i = 1 ; i < r+1 ; i++){
          dp[i][0] = 0;
        }
      
        for(int j = 1 ; j < c+1 ; j++){
            dp[0][j] = 0;
        }
        
        int ms = 0;
        for( int i = 1 ; i < r + 1 ; i++){
          for( int j = 1 ; j < c + 1 ; j++){
            if(matrix[i-1][j-1] == '1'){
              dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
            }else{
              dp[i][j] = 0;
            }
            if(dp[i][j]*dp[i][j] > ms) ms = dp[i][j]*dp[i][j];
          }
        }
        return ms;
    }
};