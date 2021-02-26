class Solution {
public:
    int mySqrt(int x) {
    
        if(x <= 1) return x;
        long left = 1;
        long right = x;
        long mid,result;
        while(left <=right){
            mid = (right+left)/2;
            if(mid*mid == x) return mid;
    
            if(x < mid*mid) 
                right = mid - 1;
            else{
                left = mid + 1;
                result = mid;
            } 
        }
        
        return result;
    }
};