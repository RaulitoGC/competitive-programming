class Solution {
public:
    
    bool isPalindrome(string s){
        int first = 0;
        int last = s.size() - 1;
        while(first < last){
            if(s[first] != s[last]){
                return false;
            }
            first++;last--;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(s.empty()) return 0;
        if(isPalindrome(s)) return 1;
        else return 2;
    }
};
