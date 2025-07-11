int mod= 1e9+7;
vector<vector<int> > dp;
int findcount(int A, int B, int C, int sum)
{
    if(sum==C && A==0)  return 1;
    if(sum>C || A<=0 || A > C-sum)   return 0;
   
    if(dp[A][sum]!=-1)  return dp[A][sum];
   
    int ans=0;
    for(int i=1; i<=B; i++)
    {
        if(C-sum < i)   break;
        ans= (ans+ findcount(A-1, B,C, sum+i)%mod)%mod;
    }
   
    return dp[A][sum] = ans;
}

int Solution::findDiceSum(int A, int B, int C) {

    dp.assign(A+1, vector<int> (C+1, -1));    
    return findcount(A, B,C, 0);
}
