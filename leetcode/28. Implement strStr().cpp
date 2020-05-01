class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        
        int haystackSize = haystack.size();
        int needleSize = needle.size();
        int index = 0;
        //cout << haystackSize - needleSize << endl;
        int n = haystackSize - needleSize;
        for(int i = 0.; i <= n; i++){
            index = 0;
            if(haystack[i] == needle[index]){
                index++;
                // cout << "--->" << haystack[i + index] << " / " << needle[index]<< endl;
                while( i + index < haystackSize && haystack[i + index] == needle[index]) index++;
                // cout << i << "---" << index << endl;
                if(index == needleSize) return i;
            }
        }
        
        return -1;
    }
};