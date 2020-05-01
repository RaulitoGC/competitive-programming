class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> result;
        
        if(n == 1){
            result.push_back(1);
            return result;
        }
        
        if(n == 2){
            result.push_back(nums[1]);
            result.push_back(nums[0]);
            return result;
        }
        
        result.push_back(nums[0]);
        for(int i = 1 ; i < n ; i++){
            result.push_back(result[i-1]*nums[i]); //[1,2,6,24]    
        }
        
        for(int i = n-2 ; i > 0 ; i--){
            nums[i] = nums[i]*nums[i+1];//[1,24,12,4]
        }
        
        result[0] = nums[1];//[24,2,6,24]
        result[n-1] = result[n-2];//[24,2,6,6]  | size = 4
        
        //result = [24,2,6,6]
        // nums = [1,24,12,4]
        
        //1
        //result = [24,12,6,6]
        // nums = [1,2,6,4]
        for(int i = 1 ; i < n - 1 ; i++){//1,2
            nums[i] = result[i];
            result[i] = nums[i-1]*nums[i+1]; //[1,24,12,4]    
        }
            
        return result;
    }
};