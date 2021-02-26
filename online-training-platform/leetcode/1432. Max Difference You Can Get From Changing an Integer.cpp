class Solution {
public:
  
    bool sameSize(int a, int b){
      int s1 = 0;
      int s2 = 0;
      while(a){
        s1++;
        a/=10;
      }
      
      while(b){
        s2++;
        b/=10;
      }
      return s1 == s2;
    }
  
    int maxDiff(int num) {
      int t = num;
      int r=1,j,k;
      long rmin = INT_MAX,rmax = INT_MIN;
      
      for(int x = 0; x <= 9; x++){
        for(int y = 0; y <= 9; y++){
          t = num;
          r = 0;
          j=0;
          while(t){
            k = t%10;
            if(k == x){
              k = y;
            }
            r = k*pow(10,j) + r;
            j++;
            t/=10;
          }
          if(r != 0 && sameSize(r,num)){
            if(r > rmax) rmax = r;
            if(r < rmin) rmin = r;
          }
        }
      }
      return rmax - rmin;
    }
};