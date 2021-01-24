class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<int> v;
        int size = matrix.size();
        vector<vector<int>> temp;
        
        
        for(int i = 0 ; i < matrix.size() ; i++){
            temp.push_back(vector<int>(matrix[i].size(), 0));
        }
        
        temp[0][0] = matrix[0][0];
        for(int i = 1 ; i < matrix.size() ; i++){
            temp[i][0] = temp[i-1][0] ^ matrix[i][0];
        }
        
        for(int j = 1; j < matrix[0].size() ; j++){
            temp[0][j] = temp[0][j - 1] ^ matrix[0][j];
        }
        
        for(int i = 1 ; i < matrix.size() ; i++){
            for(int j = 1 ; j < matrix[i].size() ; j++){
                temp[i][j] = temp[i-1][j] ^ temp[i][j-1] ^ matrix[i][j] ^ temp[i-1][j-1];
            }
        }
        
        for(int i = 0 ; i < temp.size() ; i++){
            for(int j = 0 ; j < temp[i].size() ; j++){
                //cout << temp[i][j] << " ";
                v.push_back(temp[i][j]);
            }
            //cout << endl;
        }
        //cout << endl;
        sort(v.begin(), v.end());
        // for(int i = 0 ; i < v.size() ; i++){
        //     cout << v[i] << " ";
        // }
        return v[v.size() - k];
    }
};