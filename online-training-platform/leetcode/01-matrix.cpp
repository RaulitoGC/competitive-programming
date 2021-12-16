class Solution {
public:
    
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    bool isValidPoint(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        
        while(!q.empty()) {
            pair<int,int> current = q.front();
            q.pop();
            for(int i = 0 ; i < 4 ; i++) {
                int x = current.first + dx[i];
                int y = current.second + dy[i];
                if(isValidPoint(x,y,n,m) && dist[x][y] > dist[current.first][current.second] + 1) {
                    dist[x][y] = dist[current.first][current.second] + 1;
                    q.push({x,y});
                }
            }
        }
        
        return dist;
    }
};