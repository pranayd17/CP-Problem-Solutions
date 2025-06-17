const int mod = 1e9 + 7;
const int MAX = 100005;

vector<long long> fact(MAX);
vector<long long> invFact(MAX);

// Fast exponentiation
long long power(long long x, long long y) {
    long long res = 1;
    x %= mod;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

// Precompute factorials and inverse factorials
void precomputeFactorials(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    invFact[n] = power(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
}

int Solution::solve(int A, vector<int> &B) {
    sort(B.begin(), B.end());
    precomputeFactorials(A);

    int n = A - B.size(); // Number of unoccupied positions
    long long output = fact[n];
    bool check = true;
    int idx = 0;
    int j = 0;

    for (int i = 1; i <= A; i++) {
        if (j < B.size() && i == B[j]) {
            if (check) {
                // First block
                output = (output * invFact[idx]) % mod;
                check = false;
            } else {
                // Middle blocks
                long long powval = power(2, max(0, idx - 1));
                output = (output * invFact[idx]) % mod;
                output = (output * powval) % mod;
            }
            j++;
            idx = 0;
        } else {
            idx++;
        }
    }

    // Handle the last block
    output = (output * invFact[idx]) % mod;

    return (int)output;
}
