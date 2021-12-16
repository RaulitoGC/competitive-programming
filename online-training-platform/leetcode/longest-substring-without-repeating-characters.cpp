class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, res = 0, n = s.size();
        vector<int> letters(128,0);
        while(right < n) {
            letters[s[right]]++;
            
            while(letters[s[right]] > 1) {
                letters[s[left]]--;
                left++;
            }
            
            res = max(res, right - left + 1);
            right++;
        }
        
        return res;
    }
};