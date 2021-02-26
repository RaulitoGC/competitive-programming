class Solution {
public:
    
    int findComplement(int num) {
        int temp = num;
        int c = 0;
        while(temp){
            c++;
            temp >>= 1;
        }
        int r = (pow(2,c) - 1) - num;
        return r;
    }
};

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();