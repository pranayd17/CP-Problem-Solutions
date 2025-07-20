int Solution::maxArr(vector<int> &A) {
    int n=A.size();
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=A[i]-(i+1);
    }
    int smin[n];
    smin[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        smin[i]=min(smin[i+1],a[i]);
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,a[i]-smin[i]);
    }
    int b[n];
     for(int i=0;i<n;i++)
    {
        b[i]=A[i]+(i+1);
    }
     int s1min[n];
    s1min[0]=b[0];
    for(int i=1;i<n;i++)
    {
        s1min[i]=min(s1min[i-1],b[i]);
    }
     for(int i=n-1;i>=0;i--)
    {
        ans=max(ans,b[i]-s1min[i]);
    }
    return ans;
   
   
   
   
}
