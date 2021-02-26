class Solution {
public:
    
    
    static bool comp(pair<int,int> p1, pair<int,int> p2){
        if( p1.second == p2.second ) return p1.first > p2.first;
        return p1.second > p2.second;
    }
    
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<pair<int,int>> v;
        
        sort(arr.begin(), arr.end());
        int mid = (arr.size() - 1)/2;
        int m = arr[mid];
        //cout << m << endl;
        for(int i = 0 ; i < arr.size() ; i++){
            v.push_back(make_pair(arr[i], abs(arr[i] - m)));
        }
        
        sort(v.begin(), v.end(), comp);
        
        vector<int> r;
        for(int i = 0; i < k ; i++){
            r.push_back(v[i].first);
        }
        return r;
    }
};
