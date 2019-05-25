class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        if(n <= 1) return;
        
        int first = 0;
        int last = n - 1;
        while(first < last){
            swap(s[first],s[last]);
            first++;
            last--;
        }
    }
};