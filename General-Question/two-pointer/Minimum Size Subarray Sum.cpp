class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return 0;
        int j,temp,minGroup = INT_MAX;
        
        for(int i = 0; i < n ; i++){
            j = i;
            temp = s;
            // cout << "  i ->" << i << endl;
            // cout << "TEMP ->" << temp << endl; 
            while(temp > 0  && j < n){
                temp -= nums[j];
                //cout << "temp ->" << temp << endl;
                j++;
            }
            //cout << "j ->" << j << endl;
            if( temp <= 0 && j - i < minGroup) minGroup = j - i;
            //cout << "------" << endl;
        }
        
        if(minGroup == INT_MAX) return 0;
        return minGroup;
        
    }
};