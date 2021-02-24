class Solution {
public:
    
    int scoreOfParentheses(string S) {
        int res = 0, bal = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') {
                bal++;
            } else {
                bal--;
                if (S[i-1] == '(')
                    res += 1 << bal;
            }
        }
        return res;
    }
};