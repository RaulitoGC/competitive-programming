class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int maxAcum = nums[0];
        int maxSum = nums[0];
        
        for(int i = 1; i < size; i++){
            maxAcum = max(nums[i],maxAcum + nums[i]);    
            maxSum = max(maxSum, maxAcum);
        }
                
        return maxSum;
    }
};