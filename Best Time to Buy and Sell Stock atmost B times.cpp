int Solution::solve(vector<int> &A, int B){
    int n = A.size();
    B = min(B,n-1);
    // int dp[B+1][n]; dp[i][j] = 0 to j stocks, i transactions
    int curr[n] = {0};
    int prev[n] = {0};
    int maxi;
    for(int i=1; i<=B; i++){
        maxi = -A[0];
        for(int j=1; j<n; j++){
            curr[j] = max({curr[j-1], prev[j], A[j] + maxi});
            maxi = max(maxi, prev[j-1] - A[j]);
        }
        for(int j=1; j<n; j++) prev[j] = curr[j];
    }
    return curr[n-1];
}
