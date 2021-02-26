class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> out(n+1);
        
        int L = INT_MAX,R = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if( nums[i] < L) L = nums[i];
            if( nums[i] > R) R = nums[i];
        }

        int k = R-L+1;
        int F[k];

        for(int i = 0 ; i < k ; i++) F[i] = 0;

        for(int i = 0 ; i < n ; i++) F[nums[i] - L]++;
        
        for(int i = 1 ; i < k ; i++) F[i] += F[i-1];
        
        for(int i = 0 ; i < n ; i++){
            out[F[nums[i] - L]] = nums[i]; 
            F[nums[i] - L]--;
        }
        
        int first = -1;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != out[i+1]){
                first = i;
                break;
            }
        }
        
        int last = -1;
        for(int i = n-1 ; i >= 0 ; i--){
            if(nums[i] != out[i+1]){
                last = i;
                break;
            }
        }
        return (first == -1 || last == -1)?0 : last-first+1;
    }
};
