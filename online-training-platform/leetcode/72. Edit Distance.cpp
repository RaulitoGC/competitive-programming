class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int size1 = word1.size();
        int size2 = word2.size();
        
        int dp[size1 + 1][size2 + 1];
        
        dp[0][0] = 0;
        for(int i = 1 ; i <= size1 ; i++) dp[i][0] = i;
        for(int j = 1 ; j <= size2 ; j++) dp[0][j] = j;
        
        for(int i = 1 ; i <= size1 ; i++){
            for(int j = 1 ; j <= size2 ; j++){
                if(word1[i-1] != word2[j-1]){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;    
                }else{
                    dp[i][j] = dp[i-1][j-1];
                } 
            }
        }
        return dp[size1][size2];
    }
};
