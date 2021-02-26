class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
      int size = candies.size();
      vector<bool> result;
      int m = candies[0];
      
      for( int i = 1 ; i < size ; i++){
        if(m < candies[i]) m = candies[i];
      }
      
      for( int i = 0 ; i < size ; i++){
        if(extraCandies + candies[i] >= m) result.push_back(true);
        else result.push_back(false);
      }
      
      return result;
    }
};