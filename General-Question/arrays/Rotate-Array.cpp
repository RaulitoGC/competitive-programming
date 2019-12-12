class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if( size == 1) return;
        if(k >= size){
            k = (k % size);    
        }
    
        invertArray(nums,0,size-1);
        
        // for(int i = 0; i < size ; i++){
        //     cout << nums[i] << " ";
        // }
        
        invertArray(nums,k,size-1);
        invertArray(nums,0,k-1);
           
        // for(int i = 0; i < size ; i++){
        //     cout << nums[i] << " ";
        // }
    }
    
    
    void invertArray(vector<int>& nums, int star, int end){
        int aux = 0;
        while(star < end){
            aux = nums[star];
            nums[star] = nums[end];
            nums[end] = aux;
            star++;
            end--;
        }
    }
};