class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while(left < right) {
            int currentSum = numbers[left] + numbers[right];
            
            if(currentSum < target) {
                left++;
            } else if(currentSum > target) {
                right--;
            } else{
                break;
            }
        }
        
        return {left + 1, right + 1};
    }
};