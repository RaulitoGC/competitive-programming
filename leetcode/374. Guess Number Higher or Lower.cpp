// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        if(guess(left) == 0) return left;
        int right = n;
        if(guess(right) == 0) return right;
        int mid;
        while(guess(mid) != 0){
            mid = left +  (right-left)/2;
            
            if(guess(mid) == -1) right = mid;
            else left = mid;
        }
        return mid;
    }
};