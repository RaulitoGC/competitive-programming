class Solution {
public:
    int maxArea(vector<int>& height) {
        int mA = 0;
        int size = height.size();
        int start = 0;
        int end = size - 1;

        while(start < end){
            mA = max(mA, (end - start)*min(height[start], height[end]));
        
            if( height[start] < height[end]){
                start++;
            }else{
                end--;
            }
        }

        
        return mA;
    }
};
