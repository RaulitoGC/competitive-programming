class Solution {
public:
    
    string getMissing(int start, int end) {
        if(start == end) return to_string(start);
        else return to_string(start) + "->" + to_string(end);
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int size = nums.size();
        if(size == 0) {
            return {getMissing(lower, upper)};
        }
        
        vector<string> res;
        
        // First item
        int firstItem = nums[0] - 1;
        int lastItem = nums[size - 1] + 1;
        
        if(lower <= firstItem) {
            res.push_back(getMissing(lower, firstItem));
        }
        
        for(int i = 0 ; i < size - 1 ; i++) {
            int first = nums[i] + 1;
            int second = nums[ i + 1] - 1;
            if(first <= second) {
                res.push_back(getMissing(first, second));    
            }
        }
        
        if(lastItem <= upper) {
            res.push_back(getMissing(lastItem, upper));
        }
        
        return res;
    }
};