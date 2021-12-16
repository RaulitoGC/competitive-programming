class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        int n = s.size();
        for(int i = 0 ; i < n ; i++) {
            if( s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);   
            }else if(st.empty()){
                return false;
            } else {
                char last = st.top();
                if(last != '(' && last != '{' && last != '['){
                    return false;
                } else if (last == '(' && s[i] == ')'){
                    st.pop();
                } else if (last == '[' && s[i] == ']') {
                    st.pop();
                }else if (last == '{' && s[i] == '}'){
                    st.pop();
                } else{
                    return false;
                }
            }
        }
        
        return st.empty();
    }
};