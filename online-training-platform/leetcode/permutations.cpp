class Solution {
public:
    
    vector<vector<int>> res;
    
    void permuteHelper(vector<int> current, unordered_set<int> cache, vector<int>& nums) {
        int size = current.size();
        int n = nums.size();
        if(size == n) {
            res.push_back(current);
            return;
        }
        
        for(int i = 0; i < n ; i++) {
            if(cache.find(nums[i]) == cache.end()) {
                current.push_back(nums[i]);
                cache.insert(nums[i]);
                permuteHelper(current, cache, nums);
                
                current.pop_back();
                cache.erase(nums[i]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        unordered_set<int> cache;
        permuteHelper(current, cache, nums);
        return res;
    }
};