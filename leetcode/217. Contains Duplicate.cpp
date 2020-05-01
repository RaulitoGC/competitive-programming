class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> S;
        int n = nums.size();
        for(int i = 0 ;  i < n ; i++){
            if(S.count(nums[i]) ==  1){
                return true;
            }else{
                S.insert(nums[i]);
            }
        }
        return false;
    }
};