class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int size = nums.size();
      if(size == 0){
        return 0;
      }
      
      int lastNumberRead = nums[0];
      int k = 0;
        //[0,0,1,1,1,2,2,3,3,4]
        //[1,1,2] -> 1
        // []
        // [1,1,1,1]
      for(int i = 1 ; i < size ; i++){
        int current = nums[i];
        if(lastNumberRead == nums[i]){
          nums[i] = INT_MIN;
          k++;
        }
        
        lastNumberRead = current;
      }
      
      //[1,1,2] - >[1,INT_MIN,2]
      //[0,0,1,1,1,2,2,3,3,4] - >[0,1,INT_MIN,INT_MIN,INT_MIN,2,INT_MIN,3,INT_MIN,4]
      for(int i = 1 ; i < size ; i++){
        if(nums[i] != INT_MIN){
          int idx = i - 1;
          while( idx >= 0 && nums[idx] == INT_MIN) idx--;
          
          if(nums[idx + 1] == INT_MIN){
            nums[idx + 1] = nums[i];
            nums[i] = INT_MIN;  
          }
        }
      }
      
      return size - k;
    }
};