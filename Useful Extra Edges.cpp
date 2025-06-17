int Solution::solve(int n, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
    vector<vector<int>> dis(n+1,vector<int>(2,1e9));
    dis[C][0]=0;
    dis[C][1]=0;
   
    vector<vector<pair<int,int>>> adj(n+1);
    vector<vector<pair<int,int>>> adje(n+1);
   
    for(auto &ele: B){
        adj[ele[0]].push_back({ele[1],ele[2]});
        adj[ele[1]].push_back({ele[0],ele[2]});
    }
   
    for(auto &ele: E){
        adje[ele[0]].push_back({ele[1],ele[2]});
        adje[ele[1]].push_back({ele[0],ele[2]});
    }
   
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{C,0}});
   
    while(!pq.empty()){
        auto [ds, tp] = pq.top();
        pq.pop();
        auto[node, useExtra] = tp;
       
        for(auto [node2, wt]: adj[node]){
            if(ds+wt< dis[node2][useExtra]){
                dis[node2][useExtra]=ds+wt;
                pq.push({ds+wt,{node2, useExtra}});
            }
        }
        if(useExtra==0){
            for(auto [node2, wt]: adje[node]){
                if(ds+wt< dis[node2][1]){
                    dis[node2][1]=ds+wt;
                    pq.push({ds+wt,{node2, 1}});
                }
            }
        }
    }
    if(dis[D][0]==1e9 && dis[D][1]==1e9) return -1;
    return min(dis[D][0], dis[D][1]);
}
