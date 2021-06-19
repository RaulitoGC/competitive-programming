class SparceTable {
public:
    static const int MAXN = 30000;
    static const int K = 25;
    int N = 0;
    int st[MAXN + 5][K + 1];
    
    NumArray(vector<int>& nums) {
        N = nums.size();
        for (int i = 0; i < N; i++){
            st[i][0] = nums[i];
        }
        computeSt();
    }
    
    int f(int a, int b){
        return a + b;
    }
    
    void computeSt(){ 
        for (int j = 1; j <= K; j++){
            for (int i = 0; i + (1 << j) <= N; i++){
                st[i][j] = f(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);        
            }        
        }
    }
    
    void update(int index, int val) {
        st[index][0] = val;
        computeSt();
    }
    
    int sumRange(int L, int R) {
        long long sum = 0;
        for (int j = K; j >= 0; j--) {
            if ((1 << j) <= R - L + 1) {
                sum += st[L][j];
                L += 1 << j;
            }
        }
        return sum;
    }
};