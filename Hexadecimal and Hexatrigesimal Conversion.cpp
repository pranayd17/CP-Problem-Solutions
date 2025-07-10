class Solution {
public:
    string concatHex36(int n) {
        string res1,res2;
        int num=n;
        n=n*n;
        while(n){
            int rem=n%16;
            n/=16;
            if(rem>=10){
                res1+=char(rem+55);
            }
            else res1+=to_string(rem);
        }

        n=num*num*num;
        while(n){
            int rem=n%36;
            n/=36;
            if(rem>=10){
                res2+=char(rem+55);
            }
            else res2+=to_string(rem);
        }
        reverse(res1.begin(),res1.end());
        reverse(res2.begin(),res2.end());
        return res1+res2;
    }
};
