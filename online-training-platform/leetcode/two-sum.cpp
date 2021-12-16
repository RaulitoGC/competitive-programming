class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> cache;
        
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            int complement = target - nums[i];
            if(cache.find(complement) != cache.end()) {
                return {cache[complement], i};
            }
            cache[nums[i]] = i;
        }
        
        return {};
    }
};