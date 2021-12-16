class Solution {
public:
    
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool validPoint(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int startX, int startY) {
        
        int islandNumber = 1, n = grid.size() , m = grid[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(startX, startY));
        visited[startX][startY] = true;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0 ; i < size ; i++) {
                pair<int,int> current = q.front();
                q.pop();
                
                //visited[current.first][current.second] = true;
                
                for(int i = 0 ; i < 4 ; i++) {
                    int x = current.first + dx[i];
                    int y = current.second + dy[i];
                    
                    if(validPoint(x,y,n,m) && grid[x][y] == 1 && !visited[x][y]) {
                        visited[x][y] = true;
                        q.push(make_pair(x,y));
                        islandNumber++;
                    }
                }
            }
        }
        
        return islandNumber;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size(), result = 0;
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    int currentIslands = bfs(grid, visited, i, j);
                    result = max(result, currentIslands);
                }
            }
        }
        
        return result;
    }
};