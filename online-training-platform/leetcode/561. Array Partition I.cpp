class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 2) return min(nums[0],nums[1]);
            
        int first = 0;
        int last = n - 1;
        int maxSum = 0;

        sort(nums.begin(),nums.end());
        
        while(first + 1 < last){            
            maxSum += min(nums[first],nums[first+1]);
            first +=2;
            
            maxSum += min(nums[last],nums[last - 1]);
            last -= 2;
        }
        
        if(first + 1 == last){
            //cout << nums[first] << " - " << nums[last] << endl;
            maxSum += min(nums[first],nums[last]);
        }
        return maxSum;
    }
};