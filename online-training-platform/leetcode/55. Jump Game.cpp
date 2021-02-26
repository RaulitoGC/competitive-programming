class Solution {
public:
    bool canJump(vector<int>& nums) {
      bool r = false;
      if(nums.size() == 1 || nums[0] == nums.size() - 1) return true;
      if(nums.size() == 2) return nums[0] > 0;
      if(nums[0] == 0) return false;
      int mi = nums[0], size = nums.size();
      for(int i = 1 ; i < size - 1; i++){
        if(mi < i+nums[i]) mi = i+nums[i];
        else if(nums[i] == 0 && mi <= i) return false;
        if(mi >= size - 1){
          r = true;
          break;
        }
      }
      return r;
    }
};