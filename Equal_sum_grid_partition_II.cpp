class Solution {
public:
    #define ll long long

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<ll>> sum(m, vector<ll>(n, 0));
        unordered_map<ll, int> top, bottom, left, right;

        // Compute prefix sum and initialize bottom & right frequency maps
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i][j] = grid[i][j] +
                            (i > 0 ? sum[i - 1][j] : 0) +
                            (j > 0 ? sum[i][j - 1] : 0) -
                            (i > 0 && j > 0 ? sum[i - 1][j - 1] : 0);

                if (i == 0)
                    ++top[grid[i][j]];
                else
                    ++bottom[grid[i][j]];

                if (j == 0)
                    ++left[grid[i][j]];
                else
                    ++right[grid[i][j]];
            }
        }

        ll total = sum[m - 1][n - 1];

        // Horizontal cut
        for (int i = 0; i < m - 1; i++) {
            if (sum[i][n - 1] * 2 == total)
                return true;

            ll diff = total - 2 * sum[i][n - 1];

            if (diff > 0) {
                if (i < m - 2 && n>1 && bottom.count(diff))
                    return true;
                else if (i < m - 2 && n==1 && (grid[i+1][0]==diff || grid[m-1][0]==diff))
                    return true;    
                else if (i == m - 2 && (grid[m - 1][0] == diff || grid[m - 1][n - 1] == diff))
                    return true;
            } else {
                diff = abs(diff);
                if (i > 0 && n>1 && top.count(diff))
                    return true;
                else if (i > 0 && n==1 && (grid[i][0]==diff || grid[0][0]==diff))
                    return true;     
                else if (i == 0 && (grid[0][0] == diff || grid[0][n - 1] == diff))
                    return true;
            }

            // Move row i+1 cells from bottom to top
            for (int j = 0; j < n; j++) {
                int val = grid[i + 1][j];
                ++top[val];
                if (--bottom[val] == 0)
                    bottom.erase(val);
            }
        }

        // Vertical cut
        for (int j = 0; j < n - 1; j++) {
            if (sum[m - 1][j] * 2 == total)
                return true;

            ll diff = total - 2 * sum[m - 1][j];
            if (diff > 0) {
                if (j < n - 2  && m>1 && right.count(diff))
                    return true;
                else if (j < n - 2  && m==1 && (grid[0][j+1]==diff || grid[0][n-1]==diff))
                    return true;    
                else if (j == n - 2 && (grid[0][n - 1] == diff || grid[m - 1][n - 1] == diff))
                    return true;
            } else {
                diff = abs(diff);
                if (j > 0 && m>1  && left.count(diff))
                    return true;
                else if (j > 0  && m==1 && (grid[0][j]==diff || grid[0][0]==diff))
                    return true;      
                else if (j == 0 && (grid[0][0] == diff || grid[m - 1][0] == diff))
                    return true;
            }

            // Move column j+1 cells from right to left
            for (int i = 0; i < m; i++) {
                int val = grid[i][j + 1];
                ++left[val];
                if (--right[val] == 0)
                    right.erase(val);
            }
        }

        return false;
    }
};
