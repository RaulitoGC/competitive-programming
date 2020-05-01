class Solution {
public:
    
    int gcd(int a, int b){
        return b==0? a:gcd(b, a%b);
    }
    
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        string result;
        int r = gcd(n1,n2);
        if(n1 > n2){
            for(int i = 0; i < r ; i ++){
                if(str2[i] == str1[i]){
                    result += str2[i];    
                }
            }
        }else{
            for(int i = 0; i < r; i ++){
                if(str2[i] == str1[i]){
                    result += str1[i];    
                }
            }
        }
        return result;
    }
};