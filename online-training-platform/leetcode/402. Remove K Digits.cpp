class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int size = num.size();
        if(size == k) return "0";
        int current;
        stack<char> s;
        s.push(num[0]);
        for(int i = 1 ; i < size ; i++){
            current = num[i];
            while(!s.empty() && s.top() > current && k>0){
                s.pop();
                k--;
            }
            
            if( current != '0' || !s.empty()) s.push(current);
        }
        

        while(!s.empty() && k>0){
            s.pop();
            k--;
        }

        if(s.empty()) return "0";
        
        string r = "";
        while(!s.empty()){
            r = s.top() + r;
            s.pop();
        }
        return r;
    }
};
