// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    
    int bs(int min, int max){
        long long mid;
        bool t1,t2;
        while( max - min > 1){
            mid = min + (max-min)/2;
            t1 = isBadVersion(mid);
            t2 = isBadVersion(mid+1);
            if(!t1 && t2) return mid+1;
            if(!t1) min = mid;
            else max = mid;
            
        }
        t1 = isBadVersion(min);
        t2 = isBadVersion(max);
        
        return (!t1 && t2)? max : min;
    }
    
    int firstBadVersion(int n) {
        int r = bs(1,n);
        return r;
    }
};