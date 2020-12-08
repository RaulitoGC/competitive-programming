class Solution {
public:
    
    unsigned modulo( int value, unsigned m) {
        int mod = value % (int)m;
        if (mod < 0) {
            mod += m;
        }
        return mod;
    }
    
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> r(60,0);
        int size = time.size();
        int res = 0;
        for(int i = 0 ; i < size ; i++){
            res += r[modulo(60 - time[i],60)];
            r[time[i]%60]++;
        }
        
        return res;
    }
};
