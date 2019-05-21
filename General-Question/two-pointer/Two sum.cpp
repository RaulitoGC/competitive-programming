class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        
        if(n == 2) return vector<int>{1,2};
        
        vector<int> result;
        int first = 0;
        int last = n - 1;
        
        while(numbers[first] + numbers[last] != target){
            if(numbers[first] + numbers[last] < target){
                first++;
            }else{
                last--;
            }
        } 
        
        result.push_back(first + 1);
        result.push_back(last + 1);
        
        return result;
    }
};