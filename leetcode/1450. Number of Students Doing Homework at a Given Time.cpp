class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        
        int size = startTime.size();
        int c= 0;
        for(int i = 0 ; i < size ; i++){
            if(startTime[i] <= queryTime && queryTime <= endTime[i]) c++;
        }
        
        return c;
    }
};
