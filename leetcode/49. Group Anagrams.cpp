class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        map<string,vector<string>> M;
        string sortString = "";
        for(int i = 0 ; i < size; i++){
            sortString = strs[i];
            sort(sortString.begin(), sortString.end());
            if(M.count(sortString) > 0){
                M[sortString].push_back(strs[i]);
            }else{
                vector<string> V;
                V.push_back(strs[i]);
                M[sortString] = V;
            }
        }
        
        vector<vector<string>> result;
        map<string,vector<string>>::iterator it;
        for(it  = M.begin(); it != M.end() ; it++){
            result.push_back(it->second);
        }
        return result;
    }
};