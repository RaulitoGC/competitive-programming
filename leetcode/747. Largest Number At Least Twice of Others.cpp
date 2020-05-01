class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        int max = 0;
        int maxIndex = 0;
        for( int i = 0; i < n ; i++){
            if(nums[i] > max){
                max = nums[i];
                maxIndex = i;
            } 
        }
        
        int count = 0;
        
        //cout << max << endl;
        
        for( int i = 0; i < n ; i++){
            if(nums[i]*2 <= max) count++;
            //cout << count <<endl;
            if(count == n-1) return maxIndex;
        }
        return -1;
    }
};