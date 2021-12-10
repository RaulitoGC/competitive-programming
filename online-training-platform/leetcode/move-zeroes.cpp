class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroIdx = -1, nonZeroIdx = -1;
        int n = nums.size();
        
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] != 0 && zeroIdx != -1) {
                swap(nums[i], nums[zeroIdx]);
                
                while(nums[zeroIdx] != 0 && zeroIdx < n) zeroIdx++;
            }
            
            if(nums[i] == 0 && zeroIdx == -1) {
                zeroIdx = i;
            }
            
        }
    }
};