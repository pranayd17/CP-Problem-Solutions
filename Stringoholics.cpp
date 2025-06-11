#define ll long long
#define mod (ll)1000000007
ll kmp(string s){
    vector<ll>pi(s.size());
    for(int i = 1;i<s.size();i++){
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j]){
            j=pi[j-1];
        }
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    ll k = s.size()-pi[s.size()-1];
    if(s.size()%k==0) return k;
    else return (ll)s.size();
}

ll power(ll k, ll n){
    if(n==0) return 1;
    ll temp = power(k,n/2);
    ll y = ((temp%mod)*(temp%mod))%mod;
    if(n%2==0){
        return y;
    }
    else return ((y%mod)*(k%mod))%mod;
}

int Solution::solve(vector<string> &A) {
    int n = A.size();
    vector<ll>time;
    for(int i = 0 ;i<n;i++){
        ll num = kmp(A[i]);
        ll t = 1;
        while((t*(t+1)/2)%num!=0){
            t++;
        }
        time.push_back(t);
        // cout<<t<<endl;
    }
    ll maxi = *max_element(time.begin(),time.end());
    // prime factorisation using sieve
    if(maxi==1) return 1;
    vector<ll>primes(maxi+1);
    primes[1] = 1;
    for(ll i= 2; i<primes.size();i++){
        if(primes[i]==0){
            for(ll j= i;j<primes.size();j+=i){
                if(primes[j]==0){
                    primes[j]=i;
                }
            }
        }
        // cout<<primes[i]<<endl;
    }
   
    unordered_map<ll,ll>max_mp;
    for(ll i= 0;i<time.size();i++){
        if(time[i]==1) continue;
        ll num = time[i];
        unordered_map<ll,ll>temp_mp;
        while(num>1){
            temp_mp[primes[num]]++;
            num/=primes[num];
        }
        for(auto x:temp_mp){
            if(max_mp.find(x.first)==max_mp.end()) max_mp[x.first]=0;
            max_mp[x.first]=max(max_mp[x.first],x.second);
        }
    }
    ll ans = 1;
    for(auto x: max_mp){
        ans = (ans%mod*power(x.first,x.second)%mod)%mod;
    }
    return ans;
       
}
