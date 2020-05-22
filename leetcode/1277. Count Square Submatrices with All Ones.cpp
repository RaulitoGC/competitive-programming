class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int dp[r][c];
        
        
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                dp[i][j] = matrix[i][j];
            }
        }
        
        for(int i = 1 ; i < r ; i++){
            for(int j = 1 ; j < c ; j++){
                if(dp[i][j] != 0 && dp[i-1][j-1] != 0 && dp[i-1][j] != 0 && dp[i][j-1] != 0){
                        dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;       
                }
            }
        }
        
        for(int j = 1 ; j < c ; j++){
            dp[0][j] += dp[0][j-1];
        }
        
        for(int i = 1 ; i < r ; i++){
            dp[i][0] += dp[i-1][0];
        }
        
        for(int i = 1 ; i < r ; i++){
            for(int j = 1 ; j < c ; j++){
                dp[i][j] += (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]);
            }
        }
        
        return dp[r-1][c-1];
    }
};

static auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

