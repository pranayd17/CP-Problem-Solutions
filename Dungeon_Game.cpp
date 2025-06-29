class Solution {
public:
    int m,n;
    int dp[201][201];

    int minHpPath (int i, int j, vector<vector<int>>&dungeon) {
        if (i == m || j == n)
            return INT_MAX;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == m-1 && j == n-1) {
            if (dungeon[i][j] > 0) {
                return 1;
            } else {
                return abs(dungeon[i][j])+1;
            }
        }

        int down = minHpPath(i+1, j, dungeon);
        int right = minHpPath(i, j+1, dungeon);

        int healthPt = min(down, right) - dungeon[i][j];
        dp[i][j] = max(healthPt, 1);
        
        return dp[i][j];
    }

    int calculateMinimumHP (vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        memset(dp, -1, sizeof(dp));

        return minHpPath(0, 0,dungeon);
    }
};
