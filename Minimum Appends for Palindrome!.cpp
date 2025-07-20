int Solution::solve(string A) {
    int n=A.size();
    int l=0,r=n-1,count=0;
    while(l<r)
    {
        if(A[l]==A[r])
        {
            l++;
            r--;
        }
        else
        {
            count++;
            l=count;
            r=n-1;
        }
    }
    return count;
}
