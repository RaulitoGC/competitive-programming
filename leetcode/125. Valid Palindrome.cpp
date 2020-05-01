class Solution {
public:
    bool verifyPalindrome(string ss) {
        int n = ss.size();
        for (int i = 0; i < n / 2; i++) {
            if (ss[i] != ss[n - 1 - i]) return false;
        }
        return true;
    }
    
    bool isPalindrome(string s) {
        int n = s.size();

        int ascii;
        string ss;
        for (int i = 0; i < n; i++) {
            ascii = int(s[i]);
            if ((96 < ascii && ascii < 123) || (47 < ascii && ascii < 58)) {
                ss += s[i];
            } else if (64 < ascii && ascii < 91) {
                ss += char(ascii + 32);
            }
        }
        //cout << ss << endl;
        return verifyPalindrome(ss);
    }
};
