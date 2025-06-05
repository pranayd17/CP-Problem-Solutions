class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
       int sumof=0;
        int p=x;
      while(x>0){
           sumof+=x%10;
           x/=10;
       }
        
        if(p%sumof==0) return sumof;
        else return -1;
    }
};
