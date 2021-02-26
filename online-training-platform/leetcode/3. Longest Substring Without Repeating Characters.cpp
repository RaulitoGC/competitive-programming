class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        
        map<char,bool> M1,M2;
        int n = s.size();
        for(int i = 0;  i < n ; i++){
            M1[s[i]] = true;
        }
        int j,max = -1,n2 = M1.size();
        if(n2 <= 2) return n2;
        char c;
        
        for(int i = 0; i < n ; i++){
            M2 = M1;
            j = 0;
            c = s[i+j];
            while(M2[c]){
                j++;
                M2[c] = false;
                c = s[i+j];
            }
            //cout << j << " ";
            if(j == n2) return j;
            if(max < j) max = j;
        }        
        return max;
    }
};