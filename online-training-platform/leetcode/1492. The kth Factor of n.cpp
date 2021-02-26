class Solution {
public:
        
    vector<int> divisors(int n) { 
        vector<int> v;
        for (int i=1; i<=sqrt(n); i++) { 
            if (n%i == 0) { 
                if (n/i == i){
                    v.push_back(i);
                }else{
                    v.push_back(i);
                    v.push_back(n/i);
                } 
            } 
        }
        return v;
    } 
    
    int kthFactor(int n, int k) {
    
        vector<int> v = divisors(n);
        sort(v.begin(), v.end());
        
        return (k <= v.size())? v[k-1] : -1;
    }
};
