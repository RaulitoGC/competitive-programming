class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int sizeRows = matrix.size();
        vector<int> result;
        if(sizeRows == 0) return result;
        
        int sizeColumns = matrix[0].size();
        int diagonals = sizeRows + sizeColumns - 1;
        cout << diagonals << endl;
        int i = 0 ,j = 0,c = 0,r = 0;
        int rCount = 0, cCount = 0;
        for(int index = 0 ; index < diagonals ; index++){
            if(index % 2 == 0){
                c = cCount;
                r = i;
                while( c <= j){
                    cout << r << " / " << c << endl;
                    result.push_back(matrix[r][c]);
                    r--;
                    c++;
                }
            }else{
                r = rCount;
                c = j;
                while( r <= i){
                    cout << r << " - " << c << endl;
                    result.push_back(matrix[r][c]);
                    r++;
                    c--;
                }
            }
            
            if(i + 1 < sizeRows){
                i++;
                cCount = 0;
            } else{
                cCount++;
            }
            
            if(j + 1 < sizeColumns){
                j++;
                rCount = 0;
            }else{
                rCount++;
            }
            
        }
 
        return result;
    }
};