class Solution {
public:
    const int inf = 1e9;
    
    int solve(vector<int>& a, int k) {
        if (a.empty()) return 0;
        int n = a.size();
        vector<vector<int> > dp(n + 1, vector<int>(k + 1, -inf));
        for (int i = 0; i < n + 1; i++) dp[i][0] = 0;
        dp[1][1] = a[0];
        for (int i = 2; i < n + 1; i++) 
            for (int j = 1; j < k + 1; j++)
				dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + a[i - 1]);
        return dp[n][k];
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<int> a(slices.begin(), slices.end() - 1);
        vector<int> b(slices.begin() + 1, slices.end());
        return max(solve(a, n / 3), solve(b, n / 3));
    }
};
