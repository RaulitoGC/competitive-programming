class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int n = nums.size();
      vector<vector<int>> res;
      for(int i = 0 ; i < n && nums[i] <= 0 ; i++){
        if(i == 0 || nums[i - 1] != nums[i]){
          twoSum(nums, i, res);
        }
      }
      
      return res;
    }
  
    void twoSum(vector<int>& nums, int index, vector<vector<int>>& res){
      int lo = index + 1, hi = nums.size() - 1;
      
      while(lo < hi){
        int sum = nums[lo] + nums[index] + nums[hi];
        if(sum < 0) {
          lo++;
        }else if( sum > 0) {
          hi--;
        }else {
          res.push_back({nums[lo], nums[index], nums[hi]});
          lo++; hi--;
          while( lo < hi && nums[lo - 1] == nums[lo]){
            lo++;
          }
        }
      }
    }
};