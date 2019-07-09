class Solution {
public:
    
    int bs(vector<int> nums, int left, int right, int target){
        if(left > right) return -1;
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;
        int mid;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] == target){ return mid; }
            else if(nums[mid] < target) { left = mid + 1; }
            else { right = mid - 1; }
        }
        return -1;
    }
        
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return -1;
        int pivot = nums[0],i;
        for(i = 1; i < n; i++){
            if(pivot > nums[i]) break;
            pivot = nums[i];
        }
        int possibleResult = bs(nums,0,i - 1, target);
        if(possibleResult != -1) return possibleResult;
        return bs(nums,i, n-1, target);
    }
};