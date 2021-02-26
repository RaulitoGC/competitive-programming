class Solution {
public:
    
    int pHash[26];
    int tHash[26];
    
    void getHashP(string str){
        for(int i = 0 ; i < str.size() ; i++){
            pHash[str[i] - 'a']++;
        }
    }
    
    void getHashT(string str){
        for(int i = 0 ; i < str.size() ; i++){
            tHash[str[i] - 'a']++;
        }
    }
    
    bool compareHash(string str){
        //cout <<"-->"<< str << endl;
        for(int i = 0 ; i < str.size() ; i++){
            if(tHash[str[i] - 'a'] != pHash[str[i] - 'a']) return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        if(p.empty() || s.empty() || s.size() < p.size()) return v;
        
        int size = p.size();
        getHashP(p); 
        getHashT(s.substr(0,size));
        
        if(compareHash(p)) v.push_back(0);
            
        for(int i = 1 ; i < s.size() - size +1; i++){
            //if( i + size < s.size()){
                //cout << i << endl;
                tHash[s[i-1] - 'a']--;
                tHash[s[i+size-1] - 'a']++;
                if(compareHash(p)) v.push_back(i);    
            //}
        }
        
        return v;
    }
};
