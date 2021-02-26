class Solution {
public:
    
    bool isLetter(char c){
        return 97 <= c && c <= 122;
    }
    
    string minRemoveToMakeValid(string s) {
        
        int size = s.size();
        stack<pair<char, int>> stack;
        unordered_set<int> invalids;
        for(int i = 0 ; i < size ; i++){
            if(s[i] == '('){
                stack.push(make_pair(s[i], i));
            }else if(s[i] == ')'){
                if(stack.empty()){
                    invalids.insert(i);
                }else{
                    stack.pop();
                }
            }
        }
        
        while(!stack.empty()){
            pair<char, int> p = stack.top();
            invalids.insert(p.second);
            stack.pop();
        }
        
        string res = "";
        
        for(int i = 0 ; i < size ; i++){
            if(invalids.find(i) == invalids.end()){
                res += s[i];
            }
        }
        
        return res;
    }
};
