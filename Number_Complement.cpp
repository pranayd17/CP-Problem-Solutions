class Solution {
public:
    int findComplement(int num) {
        long long n=1;
        while(n<num){
            n*=2;
        }
        if(n==num) return num-1;
        return n-num-1;
    }
};
