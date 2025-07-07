class Solution {
public:
    const int MOD = 1e9 + 7;

    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long left = min(a, b);
        long long right = 1LL * n * left;
        long long lcm = 1LL * a * b / gcd(a, b);

        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long count = mid / a + mid / b - mid / lcm;

            if (count < n)
                left = mid + 1;
            else
                right = mid;
        }

        return left % MOD;
    }
};
