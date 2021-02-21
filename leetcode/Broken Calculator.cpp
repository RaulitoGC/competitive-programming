class Solution {
public:
    int brokenCalc(int X, int Y) {
        int c = 0;
        long long y = Y, x = X;
        while(x < y){

                if(y&1){
                    y++;
                }else{
                    y /= 2;
                }
            c++;
        }
        return c + x - y;
    }
};
