class Solution {
public:
    
    vector<vector<bool>> visited;
    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
  
  
    void bfs(vector<vector<char>>& grid, int x, int y, int h, int w){
      stack<pair<int,int>> s;
      s.push(make_pair(x,y));
      
      while(!s.empty()){
        pair<int,int> p = s.top();
        s.pop();
        visited[p.first][p.second] = true;
        for(int i = 0 ; i < 4 ; i++){
          int nX = p.first + dx[i];
          int nY = p.second + dy[i];
          if( nX >= 0 && nX < h && nY >=0 && nY < w && grid[nX][nY] == '1' && !visited[nX][nY]){
            s.push(make_pair(nX,nY));
          }
        }
      }
    }
  
    int numIslands(vector<vector<char>>& grid) {
      
      if(grid.empty()) return 0;
      
      int h = grid.size();
      int w = grid[0].size();
      
      visited.clear();
      
      for(int i = 0; i < h ; i++){
        vector<bool> v;
        for(int j = 0; j < w; j++){
          v.push_back(false);
        }
        visited.push_back(v);
      }
      
      int c = 0;
      for(int i = 0; i < h ; i++){
        for(int j = 0; j < w; j++){
          if(!visited[i][j] && grid[i][j] == '1'){
            bfs(grid,i,j,h,w);
            c++;
          }
        }
      }
      return c;
    }
};

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
  }();