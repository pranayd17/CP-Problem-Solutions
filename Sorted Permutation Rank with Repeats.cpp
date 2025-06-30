int mod = 1000003;
long long power(long long a, long long b){
    if(a == 1){
        return 1;
    }
    if(a == 0){
        return 0;
    }
    if(b == 0){
        return 1;
    }
   
    long long ans = 1;
    if(b % 2 == 0){
        ans = power(a, b/2);
        ans = (ans % mod * ans % mod) % mod;
    }
    else{
        ans = (a % mod * power(a, b-1) % mod) % mod;
    }
   
    return ans;
}
long long factorial(int n){
    if(n <= 1){
        return 1;
    }
   
    return (n % mod * factorial(n-1) % mod) % mod;
}
int Solution::findRank(string s) {
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = i + 1; j < n; j++){
            if(s[i] > s[j]){
                cnt++;
            }
        }
       
        map<int, int> m;
        for(int j = i; j < n; j++){
            m[s[j]]++;
        }
       
        int fact = factorial(n-i-1);
        long long val = 1;
        for(auto i : m){
            long long d = factorial(i.second) % mod;
           
            val = (val % mod * d % mod) % mod;
        }
       
        ans = (ans % mod + (((cnt % mod * fact % mod) % mod) * power(val, mod - 2) % mod) % mod) % mod;
    }
    return ans + 1;
}
