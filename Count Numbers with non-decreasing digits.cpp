typedef long long   ll;
const ll            mod =  7 + 1e9;
const int           N   = 10 + 1e3;


/* ---------------------------------------------------------------------------------------------------- */
// init
ll  f[N][20];
ll  sum[N][20];

void init(int K) {
    memset(f, 0, sizeof(f));
    int T = 1000;
    for (int u = 0; u <  K; u++) f[1][u] = 1;
    for (int i = 2; i <= T; i++) {
        for (int u = 0; u < K; u++) {
            for (int v = u; v < K; v++) f[i][u] = (f[i][u] + f[i-1][v]) % mod;
        }
    }
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= T; i++) {
        for (int u = 0; u < K; u++) {
            for (int v = u; v < K; v++) sum[i][u] = (sum[i][u] + f[i][v]) % mod;
        } 
    }
};


/* ---------------------------------------------------------------------------------------------------- */
// Digit dp
int n;
int a[N], buf[N];

ll  dfs(int k, int beg, int K, bool limit, bool zero) {
    if (k == 0)          return 1;
    if (!limit && !zero) return sum[k][beg];
    ll  ans = 0, l = beg, r = limit ? min(a[k],K-1) : K-1;
    for (int i = l; i <= r; i++) {
        ans = ( ans + dfs(k-1, i, K, limit&&i==a[k], zero&&i==0) ) % mod;
    }
    return ans;
}

ll  solve(string& s, int K) {  
    // Prework1:    Convert to base K
    memset(buf, 0, sizeof(buf));                      
    int T = s.size();
    for (int i = 0; i < T; i++) buf[T-i] = s[i] - '0';

    memset(a, 0, sizeof(a));
    n = 0;
    while (T) {
        int val = 0;
        for (int i = T; i >= 1; i--) {
            val = val*10 + buf[i];                          buf[i] = 0;
            buf[i] = val / K;
            val %= K; 
        }
        a[++n] = val;
        while (T && buf[T] == 0) T--;
    }

    // 
    return dfs(n, 0, K, true, true);
}


class Solution {
public:
    int countNumbers(string l, string r, int K) {
        // Prework1:    DP counting
        init(K);

        // Prework2:    l -= 1
        int i = l.size() - 1;
        while (l[i] == '0') l[i--] = '9';
        l[i]--;

        return (solve(r,K) - solve(l,K) + mod) % mod;
    }
};
