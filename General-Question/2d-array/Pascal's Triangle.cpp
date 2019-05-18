class Solution {
public:
    
    void print(vector<int> v){
        for(int i = 0; i < v.size() ; i++){
            cout << v[i] <<" ";
        }
        cout << endl;
        cout << "======" << endl;
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows ==0) return result;
        vector<int> v1 = {1};
        result.push_back(v1);
        if(numRows == 1) return result;
        
        vector<int> v2 = {1,1};
        result.push_back(v2);
        if(numRows == 2) return result;
        
    
        for(int index = 2 ; index < numRows ; index++){
            vector<int> v{1};
            for(int i = 0 ; i < index - 1 ; i++){
                v.push_back(result[index-1][i] + result[index-1][i+1]);
            }
            v.push_back(1);
            print(v);
            result.push_back(v);
        }
        
        return result;
    }
};