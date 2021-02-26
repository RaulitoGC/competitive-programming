class Solution {
public:
    
    int num_to_bits[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 }; 
  
    unsigned int getBits(unsigned int num) { 
        int nibble = 0; 
        if (0 == num) return num_to_bits[0]; 

        nibble = num & 0xf; 

        return num_to_bits[nibble] + getBits(num >> 4); 
    } 
    
    vector<int> countBits(int num) {
        vector<int> r;
        
        for(int i = 0 ; i <= num ; i++){
            r.push_back(getBits(i));
        }
        //cout<<INT_MAX<<endl;
        return r;
    }
};
