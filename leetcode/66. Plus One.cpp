class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        int carry =1;
        int current;
        for(int i = n-1 ; i >= 0 ; i--){
            current = digits[i];
            digits[i] = (current + carry) % 10;
            carry = (current + carry)/10;
        }
        
        if(carry == 1){
            digits.insert(digits.begin(),1);
        }
        
        return digits;
    }
};