class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 1) return 0;
        int last = nums[0];
        int c = 1, t;
        vector<int>::iterator it = nums.begin();
        for(it++ ; it != nums.end() ;){
            t = (*it);
            if(last == t){
                c++;
            }else{
                c = 1;
            }
            
            if(c > 2){
                nums.erase(it);
            }else{
                last = (*it);
                it++;
            }
            
            
        }
        sz = nums.size();
        return sz;
    }
};
