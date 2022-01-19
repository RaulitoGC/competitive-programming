class Solution {
public:
    
    string realString(string str){
        int s = str.size();
        string r = "";
        int c = 0, j = 0, m = 0, l = 0,k = 0;
        for(int i = s-1 ; i >= 0 ;){
            if(str[i] != '#'){
                r= str[i] + r;
                i--;
            }else{
                
                if(i == 0) break;
                j = i;
                m = 0;
                l = 0;
                while(str[j] == '#'){
                    m++;
                    j--;
                }
                k = j;
                while( k >= 0 && str[k] != '#' ){
                    l++;
                    k--;
                }
                
                if( l > m ){
                    j -= m;
                    k = l - m;
                    while(c > 0 && k > 0 && j >= 0){
                        c--;
                        j--;
                        k--;
                    }    
                }else{
                    j -= l;
                    c += (m-l);    
                }
                i = j;
            }
        }
        return r;
    }
    
    bool backspaceCompare(string S, string T) {
        return realString(S) == realString(T);
    }
};