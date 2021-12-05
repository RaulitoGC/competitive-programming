auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    
    int binarySearch(int n) {
        int low = 1, high = n;
        while(low < high ) {
            int mid = low + ( high - low ) / 2;
            if(isBadVersion(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
    
    int firstBadVersion(int n) {
        return binarySearch(n);
    }
};