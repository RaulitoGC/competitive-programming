class Solution {
public:
    
    void completeZeros(string &ss, int n){
        for(int i = 0 ;  i < n ; i++){
            ss = '0' + ss;
        }
    }
    
    string addBinary(string a, string b) {
        int aLength = a.size();
        int bLength = b.size();
        
        if(aLength > bLength){
            completeZeros(b,aLength - bLength);
        }else{
            completeZeros(a,bLength - aLength);
        }
        
        
        char carry = '0' ;
        char sum = '0';
        string result = "";
        for(int i = a.size() - 1 ; i >= 0 ; i--){
            sum = a[i] ^ b[i] ^ carry;
            carry = a[i]&b[i] | a[i]&carry | b[i]&carry;
            result = sum + result;
        }
        
        if(carry == '1'){
            result = '1' + result;
        }
        
        return result;
        
    }
};
