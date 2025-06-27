int Solution::minSmoke(vector<int> &A) {
    if (A.size()==1) return 0;
    vector<vector<long long>> dp(A.size(),vector<long long>(A.size(), INT_MAX));
    vector<int> pf(A.size());
    pf[0] = A[0], dp[0][0] = 0;
    for (int i =1;i<A.size();i++)
        pf[i] = pf[i-1] + A[i], dp[i][i] = 0;
    int M = 100;
    for (int l=2;l<=A.size();l++)
        for (int i =0; i+l-1<A.size();i++)
            for (int j = i; j<i+l-1;j++){
                int p = (pf[j]-pf[i]+A[i]+M)%M, r = (pf[i+l-1]-pf[j]+M)%M;
                dp[i][i+l-1] = min(dp[i][j]+dp[j+1][i+l-1]+p*r, dp[i][i+l-1]);
            }
    return dp[0][A.size()-1];
}
