class Solution {
public:
    bool isPalindrome(string ss, int l, int r) {
        int n = l + ((r-l)/2);
        //cout << l << "-- " << r << "-- "<< n << endl;
        for (int i = l; i <= n; i++) {
            //cout << ss[i] << "-- " << ss[r - (i-l)] << endl;
            if (ss[i] != ss[r - (i-l)]) return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int n = s.size();

        int r;
        for (int l = 0; l < n / 2; l++) {
            r = n - 1 - l;
            if (s[l] != s[r]) {
                return (isPalindrome(s, l, r - 1) || isPalindrome(s, l + 1, r));

            }
        }

        return true;
    }
};
