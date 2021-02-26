class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        pair<int,int> p1 = make_pair(coordinates[0][0], coordinates[0][1]);
        pair<int,int> p2 = make_pair(coordinates[1][0], coordinates[1][1]);
        
        double m =  ((p2.second - p1.second) * 1.0) / ((p2.first - p1.first) * 1.0);
        double b = (-1.0*m)*p1.first + p1.second;
        
        double x = 0.0, y = 0.0;
    
        for(int i = 2 ; i < coordinates.size() ; i++){
            x = coordinates[i][0]*1.0;
            y = coordinates[i][1]*1.0;
            if(y != m*x + b) return false;
        }
        return true;
    }
};
