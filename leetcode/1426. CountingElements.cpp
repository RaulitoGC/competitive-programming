class Solution {
public:
    int countElements(vector<int>& arr) {
        int size = arr.size();
        set<int> S;
        for(int i = 0 ; i < size ; i++){
            S.insert(arr[i]);
        }
        int count = 0;
        for(int i = 0 ; i < size ; i++){
            if(S.count(arr[i]+1) > 0) count++;
        }
        return count;
    }
};