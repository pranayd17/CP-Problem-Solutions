class Solution {
public:
    int dp[12][1<<12];
    int f(int node,int mask,vector<vector<int>> &dist){
        int n=dist.size();
        if(mask==((1<<n)-1)) return 0;
        if(dp[node][mask]!=-1) return dp[node][mask];
        int ans=1e9;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)) continue;
            int newMask=mask|(1<<i);
            ans=min(ans,dist[node][i]+f(i,newMask,dist));
        }
        return dp[node][mask]=ans;
    }

    int shortestPathLength(vector<vector<int>>& g) {
        int n=g.size();
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
            for(auto it:g[i]){
                dist[i][it]=1;
            }
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]==1e9 || dist[k][j]==1e9) continue;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            memset(dp,-1,sizeof(dp));
            ans=min(ans,f(i,0,dist));
        }
        return ans;
    }
};
