class Solution {
public:
    
    bool visited[51][51];

    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};
    
    void bfs(vector<vector<int>>& image,int sr, int sc, int newColor){
        
        int color = image[sr][sc];
        queue<pair<int,int>> Q;
        Q.push(make_pair(sr,sc));
        pair<int,int> current;
        int x,y,width = image[0].size(),height = image.size();
        
        while(!Q.empty()){
            current = Q.front();
            Q.pop();
            image[current.first][current.second] = newColor;
            visited[current.first][current.second] = true;
            for(int i = 0 ; i < 4 ; i++){
                x = current.first + dx[i];
                y = current.second + dy[i];
                
                if(x >= 0 && x < height && y >= 0 && y < width && !visited[x][y] && image[x][y] == color){
                    
                        Q.push(make_pair(x,y));                 
                }
                
            }
            
        }
    }
    
    void init(){
        for(int i = 0 ; i < 51 ; i++){
            for(int j = 0 ; j < 51 ; j++){
                visited[i][j] = false;
            }
        }    
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        init();
        bfs(image,sr,sc,newColor);
        return image;
        
    }
};