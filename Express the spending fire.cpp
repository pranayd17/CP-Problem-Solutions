int subract(int x,int y){
    if(x==INT_MAX)return INT_MAX;
    return x-y;
}
void findFireTime(vector<vector<int>>&grid,vector<vector<int>>&fireTime){
    queue<tuple<int,int,int>>q;
    int m=grid.size(),n=grid[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1)q.push({i,j,0});
        }
    }
    vector<vector<int>>vis(grid);
    while(!q.empty()){
        auto [i,j,time]=q.front();q.pop();
        fireTime[i][j]=time;
        vis[i][j]=1;
        for(auto dir:dirs){
            int x=i+dir.first,y=j+dir.second;
            if(x>=0 && x<m && y>=0 && y<n && !vis[x][y])q.push({x,y,time+1});
        }
    }
}
int maximumMinutes(vector<vector<int>>& grid) {
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>>fireTime(m,vector<int>(n,INT_MAX));
    
    findFireTime(grid,fireTime);// min time for fire to reach each cell
    priority_queue<tuple<int,int,int,int>>pq;
    vector<vector<int>>vis(grid);
    pq.push({fireTime[0][0],0,0,0});// amongst all paths to reach last cell, the best will be the one in which the minimum value for diff(diff is the difference between time for fire to reach and time for person to reach from first cell)amongst every cell in that path, is maximum
    while(!pq.empty()){
        auto [diff,i,j,time]=pq.top();pq.pop();
        if(vis[i][j])continue;
        if(i==m-1 && j==n-1){
            if(diff==INT_MAX)return (int)1e9;
            if(diff<0)return -1;
            return diff;
        }
        vis[i][j]=1;
        for(auto dir:dirs){
            int x=i+dir.first,y=j+dir.second;
            if(x>=0 && x<m && y>=0 && y<n && !vis[x][y]){
                if(x==m-1 && y==n-1)pq.push({min(diff,subract(fireTime[x][y],(time+1))),x,y,time+1});//if we reach last cell exactly when fire arrives, its valid but in every other cell we need to reach before fire arrives
                else pq.push({min(diff,subract(fireTime[x][y],(time+2))),x,y,time+1});
            }
        }
    }
    return -1;
}
