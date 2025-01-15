class Solution {
public:
    unordered_map<long long,int> dp;
    long long f(long long n){
        if(n==1) return 0;
        if (dp.find(n) != dp.end()) return dp[n];
        if(n%2==0) {
           return dp[n]= 1+f(n/2);
        }
        else {
            return dp[n]= 1+min(f(n-1),f(n+1));
        }
        return dp[0];
    }

    int integerReplacement(int n) {
      return f(n); 
    }
};
