class Solution {
public:
     
    vector<int> getRow(int rowIndex) {
    
        vector<int> result(rowIndex + 1);
        result[0] = result[rowIndex] = 1;
        int size = result.size();
        for(int i = 1 ; i < (size+1)/2 ; i++){
            result[i] = result[size-i - 1] = ((long)result[i-1]*(size - i))/i;
        }
        return result;    
    }
};