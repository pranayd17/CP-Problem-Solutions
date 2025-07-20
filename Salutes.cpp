long Solution::countSalutes(string A) {
    string s=A;
    int n=s.size();
    vector<int>pre(n,0);
    if(s[0]=='>')pre[0]=1;
    for(int i=1;i<n;i++)pre[i]=pre[i-1]+(s[i]=='>');
   
   
    long  ans=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='<')ans+=pre[i];
    }
    return ans;
}
