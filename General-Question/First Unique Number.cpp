class FirstUnique {
public:
  
    int i = 0;
    map<int,int> m;
    vector<int> v;
  
    FirstUnique(vector<int>& nums) {
      v = nums;
      for(int j = 0 ; j < v.size() ; j++){
        m[v[j]]++;
      }
      
      if(m[v[i]] > 1){
        while(i < v.size()){
          if(m.count(v[i]) > 0 && m[v[i]] == 1) break;
          i++;
        }  
      }
    }
    
    int showFirstUnique() {
      return (i==v.size())? -1 : v[i] ;
    }
    
    void add(int value) {
      m[value]++;
      v.push_back(value);
      
      while(i < v.size()){
        if(m.count(v[i]) > 0 && m[v[i]] == 1) break;
        i++;
      }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */