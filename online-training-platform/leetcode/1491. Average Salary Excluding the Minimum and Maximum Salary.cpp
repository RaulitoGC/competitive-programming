class Solution {
public:
    double average(vector<int>& salary) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        long long sum = 0;
        for(int i = 0 ; i < salary.size() ; i++){
            sum += salary[i];
            if(salary[i] < mn) mn = salary[i];
            if(salary[i] > mx) mx = salary[i];
        }
        
        sum -= mn;
        sum -= mx;
        
        double res = sum;
        return res/(salary.size() - 2);
    }
};
