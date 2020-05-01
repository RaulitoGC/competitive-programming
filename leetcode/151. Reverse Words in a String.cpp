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
                        result = result + " " + word;
                    }
                }
                characterFound = false;
                word = "";
            }else{
                characterFound = true;
                word = s[i] + word;
            }
        }
        // cout<<"|"<<result<<"|"<<endl;
        // cout<<"|"<<word<<"|"<<endl;
        
        if(word != ""){
            if(result == ""){
                result = word;
            }else{
                result = result + " " + word;    
            }
        }
        return result;

    }
};