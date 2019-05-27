class Solution {
public:
    
    
    int heightChecker(vector<int>& heights) {
        int count = 0;
        int n = heights.size();
        int array[n];
        for(int i = 0 ; i < n ; i++){
            array[i] = heights[i];
        }
        sort(heights.begin(),heights.end());
        
        for(int i = 0 ; i < n ; i++){
            if(array[i] != heights[i]){
                count++;
            }
        }
       
        return count;
    }
};