class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int sr = mat.size();
        int sc = mat[0].size();
        
        if(sr * sc != r * c) {
            return mat;
        }
        
        vector<vector<int>> resMat(r, vector<int>(c,0));
        
        int rIndex = 0, cIndex = 0;
        for(int i = 0 ; i < sr ; i++) {
            for(int j = 0 ; j < sc ; j++) {
                resMat[rIndex][cIndex] = mat[i][j];
                cIndex++;
                if(cIndex == c) {
                    cIndex = 0;
                    rIndex++;
                }
            }
            
        }
        
        return resMat;
    }
};