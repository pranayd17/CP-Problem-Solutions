class Solution {

    pair<bool,double> dfs(int parent,int node,int t,int target,vector<int> adj[])
    {
        int size=adj[node].size();
        if(target==node)
        {
            if(t==0) return {true,1.0};
            else if(t!=0 && adj[target].size()==1) return {true,1.0};
            return {false,0};
        }
        if(t==0 || size==0) return {false,0};
        pair<bool,double> ans={false,0};
        for(auto child:adj[node])
        {
            if(child!=parent)
            {
                pair<bool,double> temp=dfs(node,child,t-1,target,adj);
                if(temp.first==true)
                {
                    ans.first=true;
                    ans.second=temp.second/(size-1);
                    break;
                }
            }
        }
        return ans;
    }

public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) 
    {
        vector<int> adj[n+1];
        adj[1].push_back(0);
        adj[0].push_back(1);
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        pair<bool,double> ans= dfs(0,1,t,target,adj);
        if(ans.first==true) return ans.second;
        return 0.0;
    }
};
