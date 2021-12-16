class Solution {
public:
    
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(target < matrix[0][0]) {
            return false;
        }    
        
        // first bs
        int low = 0, high = matrix.size() - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(matrix[mid][0] == target) {
                return true;
            } else if(matrix[mid][0] < target) {
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }
        
        //second bs
        int row = low;
        if(matrix[row][0] > target) {
            row--;
        }
        cout << row << endl;
        low = 0, high = matrix[row].size() - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(matrix[row][mid] == target) {
                return true;
            } else if(matrix[row][mid] < target) {
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }
        
        return matrix[row][low] == target;
    }
};