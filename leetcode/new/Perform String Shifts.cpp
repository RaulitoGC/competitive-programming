class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        if(shift.size() == 0 || s.size() == 0) return s;
        
        string result = "";
        int c = 0, size = shift.size(), s1,s2;
        
        for(int i = 0; i < size ; i++){
            if(shift[i][0] == 1) c+= shift[i][1];
            else c-= shift[i][1];
        }
        
        if(c == 0) return s;
        
        if(c > 0){
            if( c > s.size()) c = c % size;
            s1 = s.size() - c;

        }else{
            c = abs(c);
            if( c > s.size()) c = c % size;
            s1 = c;
        }
            
        for( int i = s1; i < s.size() ; i++){
            result+=s[i];
        }

        for( int i = 0 ; i < s1 ; i++ ){
            result+=s[i];
        }
        
        return result;
    }
};