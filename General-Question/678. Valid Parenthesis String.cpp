class Solution {
public:
    bool checkValidString(string s) {
        stack<int> O,S;
      
        int x,y;
        for(int i = 0; i < s.size() ; i++){
          if( s[i] == '(' ) {
            O.push(i);
          }else if(s[i] == ')'){
            if(O.empty() && S.empty()) return false;
            if(!O.empty()){
              O.pop();
              continue;
            } 
            if(!S.empty()){
              x = S.top();
              if(x < i){
                S.pop();
              }else{
                return false;
              } 
            }
          }else {
            S.push(i);
          }
        }
      while(!O.empty()){
        x = O.top();
        if(!S.empty()){
          y = S.top();  
        }else{
          return false;
        }
        
        if(y > x){
          O.pop();
          S.pop();
        }else{
          return false;
        }
      }
      return true;
    }
};