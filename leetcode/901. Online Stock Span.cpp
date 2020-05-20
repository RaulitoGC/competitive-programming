class StockSpanner {
private:
    stack<pair<int,int>> s;
    int index;
public:
    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        index++;
        if(s.empty()){
            s.push(make_pair(index, price));    
            return index;
        }
        
        while(!s.empty() && (s.top()).second <= price){
            s.pop();
        }
        
        //cout << "price -> " << price << endl;
        
        if(s.empty()){
            s.push(make_pair(index, price));
            return index;
        }
        pair<int,int> top = s.top(); 
        s.push(make_pair(index, price));
        // cout << price << endl;
        // cout << index << "---"<< top.first << " -- " << top.second << endl;
        return index - top.first;    
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
