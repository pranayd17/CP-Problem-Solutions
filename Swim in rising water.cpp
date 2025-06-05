class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = grid.size(), m = grid[0].size();
        int dirx[4] = {1, -1, 0, 0};
        int diry[4] = {0, 0, -1, 1};
        int val = 0;
        pq.push({grid[0][0],{0,0}});
        grid[0][0] = -1;
        while(!pq.empty())
        {
            int sz = pq.size();
            while(sz--)
            {
                pair<int, pair<int, int>> tp = pq.top();
                int x = tp.second.first, y = tp.second.second;
                pq.pop();
                val = max(val, tp.first);
                if(x == n-1 && y == m-1) return val;
                for(int i = 0; i < 4; i++)
                {
                    int nxtx = x + dirx[i];
                    int nxty = y + diry[i];
                    if(nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= m) continue;
                    if(grid[nxtx][nxty] == -1) continue;
                    pq.push({grid[nxtx][nxty],{nxtx, nxty}});
                    grid[nxtx][nxty] = -1;
                }
            }
        }
        return val;
    }
};
