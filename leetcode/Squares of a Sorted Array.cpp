class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int sz = nums.size();
        vector<int> res;
        int j = 0;
        while( j < sz && nums[j] < 0){
            j++;
        }
        int i = j - 1;
        
        cout << i << " -- " << j << endl;
        while( i >= 0 && j < sz ){
            if( -nums[i] < nums[j]){
                res.push_back(nums[i]*nums[i]);
                i--;
            }else{
                res.push_back(nums[j]*nums[j]);
                j++;
            }
        }
            
        while(i >= 0){
            res.push_back(nums[i]*nums[i]);
            i--;
        }
            
        while(j < sz){
            res.push_back(nums[j]*nums[j]);
            j++;
        }   
        
        
        return res;
    }
};
