int n,a[500005],s[3][500005],L[500005],R[500005];
const int mod = 1e9 + 7;
int f(int l,int mid,int r){
    int sum1 = ((mid - l + 1)*1ll*(s[1][r]-s[1][mid-1]+mod)%mod)%mod;
    int sum2 = ((r-mid+1)*1ll*(s[1][mid-1]-(l>=2?s[1][l-2]:0)+mod)%mod)%mod;
    int sum = (sum1 - sum2 + mod)%mod;
    int c1 = (s[2][mid-1] - (l >= 2 ? s[2][l-2]:0));
    int c2 = (s[2][r] - s[2][mid-1]);
    int odd = (c1 *1ll* (r-mid+1-c2) + c2 * 1ll * (mid-l+1-c1))%mod;
    sum=(sum+odd)%mod;
    sum=(sum*1ll*((mod+1)/2))%mod;
    return sum;
}
int Solution::solve(vector<int> &A) {
    int n=A.size();
    for(int i=1;i<=n;i++){
        a[i]=A[i-1];
        s[0][i]=(s[0][i-1]+a[i])%mod;
        s[1][i]=(s[0][i]+s[1][i-1])%mod;
        s[2][i]=(s[2][i-1]+(s[0][i]&1));
    }
    for(int i=1;i<=n;i++){
        L[i]=i-1;
        while(L[i] and a[L[i]]<a[i])
            L[i]=L[L[i]];
    }
    for(int i=n;i>=1;i--){
        R[i]=i+1;
        while(R[i]<=n and a[R[i]]<=a[i])
            R[i]=R[R[i]];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans+a[i]*1ll*f(L[i]+1,i,R[i]-1))%mod;
    }
    return ans;    
}
