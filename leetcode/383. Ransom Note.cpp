class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> um;
        
        for(int i = 0 ; i < magazine.size() ; i++){
            um[magazine[i]]++;
        }
        
        for(int i = 0 ; i < ransomNote.size() ; i++){
            if(um.count(ransomNote[i]) <= 0){
                return false;
            } else {
                if(um[ransomNote[i]] <= 0) return false;
                um[ransomNote[i]]--;
            }      
        }
        return true;
    }
};