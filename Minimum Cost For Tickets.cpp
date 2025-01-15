class Solution {
    vector<vector<int>> dp;
    int solve(vector<int>& days, vector<int>& costs, int i, int validity) {
        if(i >= days.size())
            return 0;
        if(dp[i][validity]!=-1) return dp[i][validity];
        if(days[i] <= validity)
            return solve(days, costs, i+1, validity);
        else {
            int ch1 = costs[0] + solve(days, costs, i+1, days[i]);
            int ch2 = costs[1] + solve(days, costs, i+1, days[i]+6);
            int ch3 = costs[2] + solve(days, costs, i+1, days[i]+29);
            return dp[i][validity]=min({ch1,ch2,ch3});
        }
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.clear();
        dp.resize(366,vector<int>(1003,-1));
        return solve(days, costs, 0, 0);
    }
};
