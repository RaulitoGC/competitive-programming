class Solution {
public:
    int numJewelsInStones(string J, string S) {
      unordered_set<char> us;
      int c = 0;
      for(int i = 0 ; i < J.size() ; i++){
        us.insert(J[i]);
      }
      
      for(int i = 0 ; i < S.size() ; i++){
        if(us.count(S[i]) > 0) c++;
      }
      return c;
    }
};