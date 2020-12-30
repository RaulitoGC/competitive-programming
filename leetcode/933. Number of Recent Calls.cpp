class RecentCounter {
public:
    vector<int> v;
    
    RecentCounter() {
        
    }
    
    int ping(int t) {
        v.push_back(t);
        while( v[0] < t - 3000 ){
            v.erase(v.begin());
        }
        return v.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
