class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<int> &coins,int i,int amt){
        if(i==0) {
            if(amt%coins[0]==0) return amt/coins[0];
            return INT_MAX;
        }
        if(dp[i][amt]!=-1) return dp[i][amt];
        int not_take=f(coins,i-1,amt);
        int take=INT_MAX;
        if(amt>=coins[i]){
           int res = f(coins, i, amt - coins[i]);
            if (res != INT_MAX) take = 1 + res;
        }
        return dp[i][amt]= min(take,not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.clear();
        dp.resize(n+1,vector<int> (amount+1,-1));
        int res=f(coins,n-1,amount);
        if(res!=INT_MAX) return res;
        return -1;
    }
};
