class Solution {
public:
    
    static bool comp(pair<int,int> &p1, pair<int,int> &p2){
        return (p1.second == p2.second)? p1.first < p2.first : p1.second < p2.second;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int size = mat.size();
        int c;
        vector<pair<int,int>> vp;
        for(int i = 0 ; i < size ; i++){
            c = 0;
            for(int j = 0 ; j < mat[i].size() && mat[i][j] != 0; j++){
                c++;
            }
            cout << c << endl;
            vp.push_back(make_pair(i, c));
        }
        
        vector<pair<int,int>>::iterator it;
        vector<int> res;
        sort(vp.begin(), vp.end(), comp);
        for(it = vp.begin() ; it != vp.end() && res.size() < k ; it++){
            res.push_back(it->first);
        }
        return res;
    }
};
