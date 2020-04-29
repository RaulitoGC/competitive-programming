class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
      while(m < n){
        n &=(n-1);
      }
      return m&n;
    }
};

auto speedup=[](){
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();