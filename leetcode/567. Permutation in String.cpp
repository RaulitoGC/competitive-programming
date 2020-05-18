class Solution {
public:
    
    void updateHash(int hash[], string str){
        for(int i = 0 ; i < str.size() ; i++){
            hash[str[i] - 'a']++;
        }
    }
    
    bool compareHash(int hash1[], int hash2[], string str){
        //cout << " str -> " << str << endl;
        for(int i = 0 ; i < str.size() ; i++){
            //cout  << hash1[str[i]- 'a'] << " - " << hash2[str[i]- 'a'] << endl;
            if(hash1[str[i]- 'a'] != hash2[str[i]- 'a']) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        
        if(s1.empty() || s2.empty() || s1.size() > s2.size()) return false;
        
        int i, size = s1.size();
        
        int s1Hash[26] = {0};
        int windowHash[26] = {0};
        
        string window = s2.substr(0, size);
        
        updateHash(s1Hash, s1);
        updateHash(windowHash, window);
        
        bool result = compareHash(s1Hash, windowHash, s1);
        if(result) return true;
        
        for(i = 1 ; i < s2.size() - size + 1 ; i++){
            windowHash[s2[i-1]-'a']--;
            windowHash[s2[i+size-1]-'a']++;
            if(compareHash(s1Hash, windowHash,s1)) return true;
        }
        return false;
    }
};
