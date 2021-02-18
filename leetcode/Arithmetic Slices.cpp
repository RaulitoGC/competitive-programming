class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        if(A.empty()) return 0;
        
        int res = 0;
        int c = 0;
        for(int i = 2 ; i < A.size() ; i++){
            if(A[i] - A[i-1] == A[i-1] - A[i-2]){
                c++;
            }else{
                res += ((c*(c+1))/2);
                c = 0;
            }
        }
        
        if(c != 0){
            res += ((c*(c+1))/2);
        }
        return res;
    }
};
