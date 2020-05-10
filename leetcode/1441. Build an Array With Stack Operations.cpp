class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int index = 0;
        for( int  i = 1 ; i <= n && index < target.size(); i++){
            if(i  == target[index]){
                result.push_back("Push");
                index++;
            }else{
                result.push_back("Push");
                result.push_back("Pop");
            }
        }
        return result;
    }
};
