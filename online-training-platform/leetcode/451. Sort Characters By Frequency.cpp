class Solution {
public:
    
    static bool comp(pair<char,int> p1, pair<char,int> p2){
      return p1.second < p2.second;
    }
  
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(int i = 0 ; i < s.size() ; i++){
          m[s[i]]++;
        }
        
        vector<pair<char,int>> v;
        unordered_map<char,int>::iterator it;
        for(it = m.begin() ; it != m.end() ; it++){
          v.push_back(make_pair(it->first,it->second));
        }
      
        sort(v.begin(), v.end(), comp);
        string result = "";
        for(int i = 0 ; i < v.size() ; i++){
            result = string(v[i].second,v[i].first) + result;  
        }
      return result;
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
