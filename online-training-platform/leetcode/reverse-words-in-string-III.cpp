class Solution {
public:
    
    string reverse(string str){
        int n = str.size();
        for(int i = 0 ; i < n / 2 ; i++) {
            swap(str[i], str[n - i - 1]);
        }
        return str;
    }
    
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string res = "";
        while( ss >> word) {
            res += reverse(word) + " ";
        }
        
        return res.substr(0, res.size() - 1);
    }
};