class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        
        string number = to_string(x);
        int size = number.size() - 1;
        int i;
        char t;
        if(x < 0){
            for(int i = 1; i <= size/2; i++){
                t = number[i];
                number[i] = number[size - i + 1];
                number[size - i + 1] = t;
            }    
        }else{
            for(int i = 0; i <= size/2; i++){
                t = number[i];
                number[i] = number[size - i];
                number[size - i] = t;
            }    
        } 
        size_t sz;
        long res = stol(number, &sz);
        if( res > INT_MAX || res < INT_MIN) return 0;
        return res;
        
    }
};
