class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        int current = nums[0];
        for(int i = 1; i < size ;){
            //cout << current << " - " << nums[i] << " - " << i <<endl;
            if(current == nums[i]){
                nums.erase(nums.begin() + i);
            }else{
                current = nums[i];
                i++;
            }
            size = nums.size();
        }
        
        return size;
    }
};