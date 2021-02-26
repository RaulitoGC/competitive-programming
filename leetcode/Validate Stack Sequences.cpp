class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), j = 0;
        stack<int> S;
        for(int i = 0 ; i < n ; i++){
            S.push(pushed[i]);
            while(!S.empty() && j < n && popped[j] == S.top()){
                S.pop();
                j++;
            }
        }
        return j == n;
    }
};
