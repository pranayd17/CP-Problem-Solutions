void dfs(int i, int j, vector<vector<int>>& check, vector<vector<char>>& A, vector<vector<int>>& vis, int n, int m){
    if(vis[i][j]==1 || A[i][j]=='X')return;
   
    vis[i][j]=1;
    check[i][j]=-1;
   
    if(i-1>=0)(dfs(i-1,j,check,A,vis,n,m));
    if(i+1<n)(dfs(i+1,j,check,A,vis,n,m));
    if(j-1>=0)(dfs(i,j-1,check,A,vis,n,m));
    if(j+1<m)(dfs(i,j+1,check,A,vis,n,m));
}

void Solution::solve(vector<vector<char> > &A) {
    int n=A.size(),m=A[0].size();
    vector<vector<int>> check(n,vector<int>(m,0));
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                if(A[i][j]=='O'){
                    dfs(i,j,check,A,vis,n,m);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(check[i][j]==0)A[i][j]='X';
        }
    }
}
