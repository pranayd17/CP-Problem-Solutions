string Solution::solve(string A) {
    long long int n=A.size();
    string s=A;
    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());
    //reverse
    if (s==A){
        return "-1";
    }
    for(int i=n-1;i>0;i--){
        if (A[i-1]>=A[i]){
            continue;
        }
        else{
          for(int j=n-1;j>=i;j--){
              if (A[j]>A[i-1]){
                  swap(A[j],A[i-1]);
                  break;
              }
          }
          sort(A.begin()+i,A.end());
          return A;
        }
    }
    //return A;
   
}
