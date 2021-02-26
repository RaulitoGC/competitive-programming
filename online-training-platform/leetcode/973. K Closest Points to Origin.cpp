class Solution {
public:
    
    static long square(int x){
        return x*x;
    }
    
    static double dist(int x, int y){
        return 1.0*(sqrt(square(x)*1.0 + square(y)*1.0));
    }
    
    static bool comp(vector<int> v1, vector<int> v2){
        return dist(v1[0], v1[1]) < dist(v2[0],v2[1]);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), comp);
        vector<vector<int>> v;
        for(int i = 0 ; i < K ; i++){
            v.push_back(vector<int>{points[i][0],points[i][1]});
        }
        return v;
            
    }
};
