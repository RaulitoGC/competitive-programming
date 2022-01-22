class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        int newSize = 0;
        for(int i = 0; i < n ; i++){
            if(nums[i] != val){
                nums[newSize] = nums[i];
                newSize++;
            }
        }
        
        return newSize;
    }
};