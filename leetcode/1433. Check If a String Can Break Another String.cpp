class Solution {
public:
  
    int MAX_CHARACTERS = 26;
    
    string sortString(string str){
      int charCount[MAX_CHARACTERS];
      for (int i=0; i<MAX_CHARACTERS ; i++) {
        charCount[i] = 0; 
      }
      
      string r = "";
      for (int i=0; i<str.length(); i++) {
        charCount[str[i]-'a']++; 
      }
      for (int i=0;i<MAX_CHARACTERS;i++) {
        for (int j=0;j<charCount[i];j++) {
          r += (char)('a'+i);
        }
      }
      return r;
    }
  
    
    bool checkIfCanBreak(string s1, string s2) {
      if(s1.size() != s2.size()) return false;
      
      string t1 = sortString(s1);
      string t2 = sortString(s2);
      bool b1 = true;
      bool b2 = true;
      for(int i = 0 ; i < t1.size() ; i++){
        if(t1[i] < t2[i]){
          b1 = false;
        }
        
        if(t1[i] > t2[i]){
          b2 = false;
        }
      }
      return b1 || b2;
      
    }
};