class Solution {
public:
    
    void printTriangle(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        for(int i = 0 ; i < n ; i++) {
            int size = triangle[i].size();
            for(int j = 0 ; j < size ; j++) {
                cout << triangle[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        if(n == 1) {
            return triangle[0][0];
        }
        
        triangle[1][0] = triangle[0][0] + triangle[1][0];
        triangle[1][1] = triangle[0][0] + triangle[1][1];
        
        if(n == 2) {
            return min(triangle[1][0], triangle[1][1]);
        }
        
        printTriangle(triangle);
        for(int i = 2 ; i < n ; i++) {
            int size = triangle[i].size();
            triangle[i][0] = triangle[i-1][0] + triangle[i][0];
            for(int j = 1 ; j < size - 1 ; j++) {
                triangle[i][j] = min(triangle[i][j] + triangle[i - 1][j], triangle[i][j] + triangle[i - 1][j - 1]);
            }
            triangle[i][size - 1] = triangle[i-1][size - 2] + triangle[i][size - 1];
        }
        
        int size = triangle[n - 1].size();
        int res = INT_MAX;
        for(int i = 0 ; i < size ; i++) {
            res = min(res, triangle[n-1][i]);
        }
        return res;
    }
};