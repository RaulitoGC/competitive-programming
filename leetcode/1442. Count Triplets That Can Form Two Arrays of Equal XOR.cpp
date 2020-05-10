class Solution {
public:
        
    int countTriplets(vector<int>& arr) {
        
        int size = arr.size();
        int v1[size];
        int t1= arr[0]; 
        v1[0] = t1;

        for(int i = 1; i < size; i++){
            t1 = t1^arr[i];
            v1[i] = t1;
        }
        
        int c = 0;

        for(int i = 0; i < size; i++){
            for(int k = size-1; k >= i; k--){
                for(int j = i+1; j <= k; j++){
                    if(i == 0){
                        if( v1[j-1] == (v1[k]^v1[j-1]) ) c++;        
                    }else{
                        if( (v1[i-1]^v1[j-1]) == (v1[k]^v1[j-1]) ) c++;
                    }
                }
            }
        }
        
        return c;
    }
};
