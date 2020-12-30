class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int sz = arr.size();
        if(sz < 3) return false;
        
        vector<int> up(sz);
        vector<int> down(sz);
        
        int i = 1;
        up[0] = 0;
        while(i < sz && arr[i-1] < arr[i]){
            up[i] = 1;
            i++;
        }
        
        while(i < sz){
            up[i] = 0;
            i++;
        }
        
        i = sz - 2;
        down[sz - 1] = 0;
        while( 0 <= i && arr[i] > arr[i+1]){
            down[i] = -1;
            i--;
        }
        
        while(i >= 0){
            down[i] = 0;
            i--;
        }
        
        for(i = 0 ;i < sz ; i++){
            //cout << arr[i] << " : " << up[i] << " -- " << down[i] << endl;
            if(up[i] == 1 && down[i] == -1) return true;
            
        }
        
        return false;
    }
};
