class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        
        int size = A.size();
        
        int maxValue = A[0];
        int negTotal = A[0]*-1;
        
        int sumAcum = A[0];
        int maxSum = A[0];
        
        int minAcum = A[0];
        int minSum = A[0];
        
        for(int i = 1; i < size; i++){
            maxValue = max(maxValue,A[i]);
            negTotal += (A[i]*-1);
            
            sumAcum = max(sumAcum + A[i], A[i]);
            maxSum = max(maxSum, sumAcum);
            
            minAcum = min(minAcum + A[i], A[i]);
            minSum = min(minSum, minAcum);
        }
        
        if(maxValue <=0) return maxValue;
        
        return max(maxSum, abs(negTotal + minSum));
    }
};
