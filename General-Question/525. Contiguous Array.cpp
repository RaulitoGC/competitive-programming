class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int maxSize = 0;
        int c = 0;
        map<int, int> m;
        m[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) c--;
            else c++;
            
            nums[i] = c;
            
            if(m.count(nums[i]) > 0){
                maxSize = max(maxSize, i - m[nums[i]]);
            }else{
                m[nums[i]] = i;
            }
        }
        return maxSize;
    }
};