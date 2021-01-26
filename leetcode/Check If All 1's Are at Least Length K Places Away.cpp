class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastOneFound = -1;
        for(int i = 0; i < nums.size() ; i++){
            if(nums[i] == 1){
                if(lastOneFound != -1){
                    cout << i - lastOneFound - 1 << endl;
                    if(i - lastOneFound - 1< k){
                        return false;
                    }
                }
                lastOneFound = i;
            }
        }
        return true;
    }
};
