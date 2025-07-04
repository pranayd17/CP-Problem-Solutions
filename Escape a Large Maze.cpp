class Solution {
    int di[4] = {0,0,1,-1};
    int dj[4] = {1,-1,0,0};
public:
    bool  isinside(int r, int c, int m, int n)
    {
        return r>=0 && r< m && c>=0 && c<n;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if(blocked.size()<=1)
        return 1;

        vector<int>xs;
        vector<int>ys;
        //first make a list of all unique x and y coords
        xs.push_back(source[0]);
        xs.push_back(target[0]);
        ys.push_back(source[1]);
        ys.push_back(target[1]);

        xs.push_back(0);
        xs.push_back(999999);
        ys.push_back(0);
        ys.push_back(999999);
        for(vector<int>&b: blocked)
        {
            xs.push_back(b[0]);
            ys.push_back(b[1]);
        }
        sort(xs.begin(),xs.end());
        sort(ys.begin(),ys.end());

        
        int si = xs.size();
        for(int i = 1; i < si; i++)
        {
            if(xs[i] > xs[i-1]+1 ) //if coordinates are not adjacent, we add an extra coordinate between them
            xs.push_back(xs[i-1]+1);
            if(ys[i] > ys[i-1]+1)
            ys.push_back(ys[i-1]+1);
        }
        

        sort(xs.begin(),xs.end());
        sort(ys.begin(),ys.end());

        unordered_map<int,int>old_newx; //map old indices to new indices in compressed space
        unordered_map<int,int>old_newy;
        int idx=0;
        for(int i=0;i<xs.size();i++)
        {
            if(i > 0 && xs[i] == xs[i-1])
            continue;
            old_newx[xs[i]] = idx++;
        }
        idx=0;
        for(int i=0;i<ys.size();i++)
        {
            if(i > 0 && ys[i] == ys[i-1])
            continue;
            old_newy[ys[i]] = idx++;
        }

        int n = old_newx.size();
        int m = old_newy.size();
        vector<vector<int>>grid(m,vector<int>(n,1));

        int sr = old_newy[source[1]];
        int sc = old_newx[source[0]];
        int tr = old_newy[target[1]];
        int tc = old_newx[target[0]];
        for(vector<int>&b: blocked)
        {
            int r = old_newy[b[1]]; //find new coordinates of blocked spaces and make them 0 in new compressed space grid
            int c = old_newx[b[0]];
            grid[r][c] = 0;
        }
        //now just do bfs
        queue<pair<int,int>>bfs;
        bfs.push({sr,sc});
        grid[sr][sc] = 0;
        while(!bfs.empty())
        {
            int cur_r = bfs.front().first;
            int cur_c = bfs.front().second;
            bfs.pop();
            for(int k=0;k<4;k++)
            {
                int new_r = cur_r + di[k];
                int new_c = cur_c + dj[k];
                if(isinside(new_r, new_c, m, n) && grid[new_r][new_c]==1)
                {
                    if(new_r==tr && new_c==tc)
                    return 1;
                    grid[new_r][new_c] = 0;
                    bfs.push({new_r,new_c});
                }
            }
        }
        return 0;

    }
};
