class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int size = nums.size();
        int ones = 0;
        int zeros = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 1) ones++;
            if(nums[i] == 0) zeros++;
        }
        
        if(ones == nums.size()) return ones-1;
        if(zeros == nums.size()) return 0;
        
        
        for(int i = 1; i < size ; i++){
            if(nums[i] != 0){
                nums[i] += nums[i-1];
            }
        }

        for(int i = size - 2; i >= 0 ; i--){
            if(nums[i] != 0 && nums[i+1] !=0){
                nums[i] = nums[i+1];
            }
        }

        int mx = 0;
        for(int i = 0; i < size ; i++){
            if(nums[i] == 0){
                if( i == 0){
                    mx = max(mx, nums[i+1]);
                } else if(i == (size - 1)){
                    mx = max(mx, nums[i-1]);
                }else{
                    mx = max(mx, nums[i-1] + nums[i+1]);
                }
            }
        }
        
        return mx;
    }
};
