class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        vector<int> res;
        while(left <= right) {
            int leftSquare = nums[left]*nums[left];
            int rightSquare = nums[right]*nums[right];
            if(leftSquare < rightSquare){
                res.insert(res.begin(), rightSquare);
                right--;
            } else {
                res.insert(res.begin(), leftSquare);
                left++;
            }
        }
        
        return res;
    }
};