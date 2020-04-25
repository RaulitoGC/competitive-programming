class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
      
      if(grid.empty()) return 0;
      
      if(grid.size() == 1 && grid[0].size() ==1) return grid[0][0];
      
      int h = grid.size();
      int w = grid[0].size();
      
      int dp[h][w];
      
      dp[0][0] = grid[0][0];
      for(int i = 1 ; i < h ; i++){
        dp[i][0] = grid[i][0] + dp[i-1][0];
      }
      
      for(int j = 1 ; j < w ; j++){
        dp[0][j] = grid[0][j] + dp[0][j-1];
      }
      
      for(int i = 1; i < h; i++){
        for(int j = 1 ; j < w ; j++){
          dp[i][j] = min(dp[i-1][j] + grid[i][j], dp[i][j-1] + grid[i][j]);
        }
      }
      
      return dp[h-1][w-1];
    }
};

auto speedup=[](){
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
return nullptr;
}();