class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        unordered_map<int,int> um;
        um[0] = -1;
        int maxSize = 0, sum = 0;
        for(int i = 0; i < nums.size() ; i++){
            if(nums[i] == 0) sum -= 1;
            else sum += 1;
            if(um.count(sum) > 0){
                maxSize = max(maxSize, i - um[sum]);
            }else{
                um[sum] = i;
            }
        }
        return maxSize;
    }
};
