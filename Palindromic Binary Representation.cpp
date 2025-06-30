int Solution::solve(int A) {
    if(A == 1) return 1;
    if(A == 2) return 3;
    vector<int> a(28);
    a[0] = 0;
    int shift = 0,s = 0;
    for(int i = 1;i < 28;i += 2){
        if(i == 27) a[i] = (1 << shift);
        else{
            a[i] = (1 << shift);
            a[i+1] = (1 << shift);
        }
        shift++;
    }
    for(int i = 1;i < 28; ++i){
        a[i] += a[i-1];
    }
    int i = lower_bound(a.begin(),a.end(),A) - a.begin();
    int ans = 0;
    if(a[i] == A){
        for(int j = 0;j < i; ++j){
            ans |= (1 << j);
        }
    }else{
        ans |= (1 << (i-1));
        ans |= (1 << 0);
        int b = A - a[i-1] - 1;
        int shift1 = 0;
        for(int j = i/2;j <= i-2; ++j){
            if(b & (1 << shift1)){
                ans |= (1 << j);
            }
            shift1++;
        }
        shift1 = i-2;
        for(int j = 1;j <= (A/2)-1; ++j){
            if(ans & (1 << shift1)){
                ans |= (1 << j);
            }
            shift1--;
        }
    }
    return ans;
}
