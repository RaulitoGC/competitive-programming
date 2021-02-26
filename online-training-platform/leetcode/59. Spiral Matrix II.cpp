class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int ii = 0, ie = n;
        int ji = 0, je = n;
        int i, j;
        vector<vector<int>> res(n, vector<int>(n, -1));
        int value = 1;
        while(value <= n*n){
            
            for(j = ji; j < je ; j++){
                res[ii][j] = value;
                value++;
            }
            ii++;
            for(i = ii; i < ie ; i++){
                res[i][je - 1] = value;
                value++;
            }
            je--;
            for(j = je - 1; j >= ji ; j--){
                res[ie - 1][j] = value;
                value++;
            }
            ie--;
            for(i = ie - 1; i >= ii ; i--){
                res[i][ji] = value;
                value++;
            }
            ji++;
        }
        
        return res;
    }
};
