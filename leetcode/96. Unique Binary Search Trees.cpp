class Solution {
public:
    int numTrees(int n) {
        long long cn = 1;
        if(n == 1) return cn;
        for(int i = 2; i <= n; i++){
            cn = (2*(2*i-1)*cn)/(i+1);
        }
        return cn;
    }
};
