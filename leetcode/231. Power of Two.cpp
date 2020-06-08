class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        n&=(n-1);
        return n == 0;
    }
};

auto speedup=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
