class Solution {
public:
    
    vector<string> split(const string& s, char delimiter){
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)){
            tokens.push_back(token);
        }
        return tokens;
    }
    
    bool wordPattern(string pattern, string str) {
        map<char, string> m;
        vector<string> words = split(str, ' ');
        if(pattern.length() != words.size()) return false;
        int size = words.size();
        string word;
        char character;
        for(int i = 0 ; i < size; i++){
            word = words[i];
            character = pattern[i];
            if(m.count(character) > 0){
                if(m[character] != word) return false;
            }else{
                for(map<char,string>::iterator it = m.begin() ; it != m.end() ; it++){
                    if(it->second == word) return false;
                }
        
                m[character] = word;  
            }
        }
        
        
        return true;
    }
};
