class Solution {
public:
    
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    bool verifyPoint(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        
        int res = -1;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0 ; i < size ; i++) {
                pair<int,int> current = q.front();
                q.pop();
                
                for(int idx = 0 ; idx < 4 ; idx++){
                    int x = current.first + dx[idx];
                    int y = current.second + dy[idx];
                    
                    if(verifyPoint(x, y, n, m) && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }
            }
            res++;
        }
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        
        return res == -1 ? 0 : res;
    }
};