const long long int M=1e9+7;

vector<vector<long long int>> mul(vector<vector<long long int>>& a, vector<vector<long long int>>& b){
    vector<vector<long long int>> ans(a.size(),vector<long long int>(b[0].size(),0));
    for(long long int i=0;i<a.size();i++){
        for(long long int j=0;j<b[0].size();j++){
            for(long long int k=0;k<a[0].size();k++){
                ans[i][j]+=(a[i][k]*b[k][j])%M;
            }
        }
    }
    return ans;
}

int Solution::solve(int A) {
   
    if(A==1||A==2) return 1;
   
    // O(n) approach
   
    // long long long long int a=1,b=1;
    // for(long long int i=2;i<A;i++){
    //     long long long long int temp=b;
    //     b=(a+b)%M;
    //     a=temp;
    // }
    // return b;
   
   
    // O(logn) approach (matrix exponentiation)
   
    vector<vector<long long int>> x={{1,1},{1,0}},ans={{1,0},{0,1}},base={{1},{1}};
   
    long long int p=A-2;
    while(p>0){
        if(p%2) ans=mul(ans,x);
        x=mul(x,x);
        p/=2;
    }
    ans=mul(ans,base);
    return ans[0][0]%M;
}
