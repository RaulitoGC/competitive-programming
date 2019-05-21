class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        int sumOnes = 0;
        int maxGroup = 0;
        
        for(int i = 0; i < n ; i++){
            if(nums[i] == 1){
                sumOnes++;
            }else{
                if(sumOnes > maxGroup){
                    maxGroup = sumOnes;
                }
                sumOnes = 0;
            }
        }
        
        if(sumOnes > maxGroup){
            maxGroup = sumOnes;
        }
            
        return maxGroup;
    }
};