class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        long long inf = 1e9;
        vector<vector<int>> dp(cost.size()+1, vector<int>(cost.size()+1, inf));
        for(int i = 0; i < dp.size(); i++){
            dp[i][0] = 0;
        }

        for(int i = 1; i <= cost.size(); i ++){
            for(int j = 1; j <= cost.size(); j++){
                int not_take = dp[i-1][j];
                int take = dp[i-1][max(j-time[i-1]-1, 0)] + cost[i-1];
                dp[i][j] = min(take, not_take);
            }
        }

        return dp[cost.size()][cost.size()];        
    }
};
