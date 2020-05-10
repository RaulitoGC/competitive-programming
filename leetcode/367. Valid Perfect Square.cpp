class Solution {
public:
    
    int floorSqrt(int x) {     
        
        if (x == 0 || x == 1)  return x; 

        int l = 1, r = x >> 1, ans;    
        while (l <= r)  {
            long mid = l + ((r - l) >> 1); 
            
            if (mid * mid == x) return mid; 

            if (mid*mid < x) { 
                l = mid + 1; 
                ans = mid; 
            }  
            else r = mid-1;  
        } 
        return ans; 
        
    }
    
    bool isPerfectSquare(int num) {
        int ans = floorSqrt(num);
        return ans*ans == num;
    }
};
