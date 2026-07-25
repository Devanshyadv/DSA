class Solution {
public:
    int maxProduct(int n) {
        int firstmax=0;
        int secmax=0;
        while(n>0){
          if(n%10>firstmax){
            secmax=firstmax;
            firstmax=n%10;
          }
          else if(n%10>secmax && n%10<=firstmax){
            secmax=n%10;
          }
          n=n/10;
        }
        return firstmax*secmax;
    }
};