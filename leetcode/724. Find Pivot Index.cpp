class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;
        int V1[n];
        int sum = 0;
        
        for(int i = n-1 ; i >= 0 ; i--){
            sum+=nums[i];
            V1[i] = sum;
        }
        
        // for(int i= 0; i < n ; i++){
        //     cout << V1[i]<< " ";
        // }
        
        sum = 0;
        // cout << n-1 << endl;
        for(int i = 0 ; i < n ; i++){
            sum+=nums[i];
            //cout << i << " " << sum<< endl;
            if(V1[i] == sum) return i;
        }
        return -1;
    }
};