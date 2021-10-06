class Solution {
public:
  
    int romanToInt(string s) {
      int size = s.size();
      if(size == 0){
        return 0;
      }
      
      map<char, int> ROMAN_TO_NUMBER;
      ROMAN_TO_NUMBER['I'] = 1;
      ROMAN_TO_NUMBER['V'] = 5;
      ROMAN_TO_NUMBER['X'] = 10;
      ROMAN_TO_NUMBER['L'] = 50;
      ROMAN_TO_NUMBER['C'] = 100;
      ROMAN_TO_NUMBER['D'] = 500;
      ROMAN_TO_NUMBER['M'] = 1000;
      
      char lastCharacterRead = s[size - 1];
      int res = ROMAN_TO_NUMBER[lastCharacterRead];
       
      for(int i = size - 2 ; i >= 0 ; i--){
        char current = s[i];
        if(ROMAN_TO_NUMBER[current] < ROMAN_TO_NUMBER[lastCharacterRead]){
          res -= ROMAN_TO_NUMBER[current];
        }else{
          res += ROMAN_TO_NUMBER[current];  
        }
        lastCharacterRead = current;
      }
      
      return res;  
    }
};