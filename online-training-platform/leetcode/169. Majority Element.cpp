class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        int size = nums.size();
        for(int i = 0 ; i < size ; i++){
            m[nums[i]]++;
            if(m[nums[i]] > size/2) return nums[i];
        }
        return -1;
    }
};