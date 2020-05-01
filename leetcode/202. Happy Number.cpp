class Solution {
public:
    
    int square(int n){
        return n*n;
    }
    
    int getSumOfDigits(int n){
        if(n == 0) return n;
        return square(n%10) + getSumOfDigits(n/10);
    }
    
    bool isHappy(int n) {
        unordered_set<int> S;
        
        while(S.count(n) == 0){
            S.insert(n);
            n = getSumOfDigits(n);
        }
        
        return n==1;
    }
};