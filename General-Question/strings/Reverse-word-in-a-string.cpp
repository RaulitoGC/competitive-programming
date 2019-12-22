class Solution {
public:
    string reverseWords(string s) {
        
        int size = s.size();
        string result = "";
        string word = "";
        bool characterFound = false;
        for(int i = 0 ; i < size ; i++){
            if(s[i] == ' '){
                if(characterFound){
                    if(result == ""){
                        result = word;    
                    }else{
                        result = word + " " + result;
                    }
                }
                characterFound = false;
                word = "";
            }else{
                characterFound = true;
                word += s[i];
            }
        }
        // cout<<"|"<<result<<"|"<<endl;
        // cout<<"|"<<word<<"|"<<endl;
        
        if(word != ""){
            if(result == ""){
                result = word;
            }else{
                result = word + " " + result;    
            }
        }
        return result;
    }
};