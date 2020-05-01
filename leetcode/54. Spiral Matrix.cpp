class Solution {
public:
    
    void print(vector<int> v){
        for(int i = 0; i < v.size() ; i++){
            cout << v[i] << " ";
        }
        cout<< endl;
        cout << "=============" << endl;
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int sizeRows = matrix.size();
        vector<int> result;
        if(sizeRows == 0) return result;
        
        int sizeColumns = matrix[0].size();
        
        int i,j;
        int l = 0, r = sizeColumns - 1, b = sizeRows - 1, t = 0;
        while(result.size() < sizeRows*sizeColumns){
            j = l;
            while(j <= r){
                result.push_back(matrix[t][j]);
                j++;
            }
            t++;
            //print(result);
            if(result.size() == sizeRows*sizeColumns) break;
            
            i = t;
            //cout << "b ->" << b<< endl;
            while(i <= b){
                //cout << i << " ";
                result.push_back(matrix[i][r]);
                i++;
            }
            r--;
            //print(result);
            if(result.size() == sizeRows*sizeColumns) break;
            
            j = r;
            while(l <= j){
                //cout << j << " ";
                result.push_back(matrix[b][j]);
                j--;
            }
            b--;
            //print(result);
            if(result.size() == sizeRows*sizeColumns) break;
            
            i = b;
            //cout << t <<" == "<< i <<endl;
            while(t <= i){
                
                result.push_back(matrix[i][l]);
                i--;
            }
            l++;
            //print(result);
            if(result.size() == sizeRows*sizeColumns) break;
            
        }

        return result;
    }
};