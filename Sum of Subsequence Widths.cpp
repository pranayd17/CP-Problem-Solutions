class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long result = 0, pow2 = 1;
        
        for (int i = 0; i < n; ++i) {
            result = (result + (long long)(nums[i]) * pow2 - (long long)(nums[n - 1 - i]) * pow2) % MOD;
            pow2 = (pow2 * 2) % MOD;
        }
        
        return (result + MOD) % MOD;
    }
};
