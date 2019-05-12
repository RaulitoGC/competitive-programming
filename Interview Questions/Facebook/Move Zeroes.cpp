class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0;
        int size = nums.size();
        int index = 0;
        while(index < size){
            if(nums[index] == 0){
                nums.erase(nums.begin()+index);
                zeros++;
            }else{
                index++;
            }
            size = nums.size();
        }
        while(zeros>0){
            nums.push_back(0);
            zeros--;
        }
    }
};
