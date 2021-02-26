class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        
        int size = nums.size();
        
        if(target <= nums[0]) return 0;
        if(target == nums[size - 1]) return size - 1;
        if(target > nums[size - 1]) return size;
        
        int lo = 0;
        int hi = size - 1;
        int mid = lo;
        while(lo < hi) {
            mid = lo + (hi - lo)/2;
            if(target == nums[mid]) return mid;
            if(target < nums[mid]){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        cout << nums[lo] <<" - " << nums[hi] << endl;
        return hi;
    }
};
