class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n < 3){
            return vector<vector<int>>();
        }
        
        set<vector<int>> result;
        sort(nums.begin(), nums.end()); 
        
        int l = 1,r = n-1,x = nums[0];
    
        if(l < n && nums[l] == nums[r] && x == nums[l] && nums[l]+nums[r]+x == 0){
            vector<int> v{x,nums[l],nums[r]};
            result.insert(v);
        }else{
            for (int i=0; i < n-1; i++){ 

                l = i + 1; 
                r = n - 1; 
                x = nums[i];

                while (l < r){ 
                    if (x + nums[l] + nums[r] == 0) { 
                        vector<int> v{x,nums[l],nums[r]};
                        sort(v.begin(),v.end());
                        result.insert(v);
                        l++; 
                        r--; 
                    }else if (x + nums[l] + nums[r] < 0){
                        l++;
                    }else{
                        r--;
                    }    
                } 
            }
        }
        
        return vector<vector<int>>(result.begin(),result.end());
    }
};
