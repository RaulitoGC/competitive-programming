class Solution {
public:
    
    bool isInOrderReverse(vector<int>& prices){
        int size = prices.size();
        for(int i = 1; i < size; i++){
            if(prices[i-1] < prices[i]) return false;
        }
        return true;
    }
    
    bool isInOrder(vector<int>& prices){
        int size = prices.size();
        for(int i = 1; i < size; i++){
            if(prices[i-1] > prices[i]) return false;
        }
        return true;
    }
    
    int getIndexForSell(vector<int>& prices, int indexForBuy){
        int size = prices.size();
        while(indexForBuy + 1 < size && prices[indexForBuy] < prices[indexForBuy+1]){
            indexForBuy++;
        }
        return indexForBuy;
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        int size = prices.size();
        
        if(isInOrder(prices)) return prices[size - 1] - prices[0];
        if(isInOrderReverse(prices)) return 0;
        
        int indexForBuy = 0;
        int indexForSell = 0;
        int total = 0;
        int index = 1;
        for(; index < size; ){
            if(prices[index] > prices[index-1]){
                indexForBuy = index - 1;
            }else{
                index++;
                continue;  
            }
            indexForSell = getIndexForSell(prices,indexForBuy);
            total += prices[indexForSell] - prices[indexForBuy];
            index = indexForSell + 2;
        }
        return total;
    }
};