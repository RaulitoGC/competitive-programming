class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {      
        map<int,int> m;
        int c = 0, acum = nums[0];
        m[nums[0]] = 1;
        if(nums[0] == k){
          c++;
        } 
        for(int i = 1; i < nums.size(); i++){
          acum += nums[i];
          if(acum == k){
            c++;
          }
          
          if(m.count(acum - k) > 0){
            c += m[acum-k]; 
          }
          m[acum]++;
        }
      return c;
    }
};