class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.empty() || B.empty()) return vector<vector<int>>();
        int aSize = A.size();
        int bSize = B.size();
        int t1,t2;
        vector<vector<int>> result;
        if(A[aSize-1][1] < B[bSize-1][1]){
            
            for(int i = 0 ; i < bSize ; i++){
                
                for( int j = 0 ; j < aSize ; j++){
                    if(A[j][0] > B[i][1] ) break;
                    else if(B[i][0] < A[j][1]){
                        t1 = max(A[j][0],B[i][0]);
                        t2 = min(A[j][1],B[i][1]);
                        result.push_back(vector<int>{t1,t2});
                    } 
                    else if(B[i][0] ==  A[j][1]) result.push_back(vector<int>{B[i][0],A[j][1]});
                    else if(B[i][1] ==  A[j][0]) result.push_back(vector<int>{B[i][1],A[j][0]});
                    else if(B[i][0] ==  A[j][0]) {
                        t1 = min(A[j][1], B[i][1]);
                        result.push_back(vector<int>{B[i][0],t1});
                    }else if(B[i][1] ==  A[j][1]){
                        t1 = max(A[j][0], B[i][0]);
                        result.push_back(vector<int>{t1,B[i][1]});
                    }
                }
            }
                
        }else{                
            
            for(int i = 0 ; i < aSize ; i++){
                for( int j = 0 ; j < bSize ; j++){
                    //cout << B[j][0] << " - " << B[j][1] << " - " <<A[i][0] << " - " << A[j][1]<<endl;
                    if(B[j][0] > A[i][1] ) break;
                    else if(A[i][0] < B[j][1]){
                        t1 = max(A[i][0],B[j][0]);
                        t2 = min(A[i][1],B[j][1]);
                        result.push_back(vector<int>{t1,t2});
                    } 
                    else if(A[i][0] ==  B[j][1]) result.push_back(vector<int>{A[i][0],B[j][1]});
                    else if(A[i][1] ==  B[j][0]) result.push_back(vector<int>{A[i][1],B[j][0]});
                    else if(A[i][0] ==  B[j][0]) {
                        t1 = min(B[j][1], A[i][1]);
                        result.push_back(vector<int>{A[i][0],t1});
                    }else if(A[i][1] ==  B[j][1]){
                        t1 = max(B[j][0], A[i][0]);
                        result.push_back(vector<int>{t1,A[i][1]});
                    }
                }
            }
            
        }
        
        return result;
    }
};
