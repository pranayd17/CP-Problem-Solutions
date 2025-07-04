class Solution {
public:
    int dp[14][1<<14];
    int solve(vector<int> &nums1, vector<int> &nums2, int pos, int mask) {
        int n = nums1.size();
        if(pos >= n) return 0;
        if(dp[pos][mask] != -1) return dp[pos][mask];
        int mi = INT_MAX;
        for(int i = 0;i < nums2.size();i++) {
            if((mask & (1 << i)) == 0) {
                mi = min(mi, (nums1[pos] ^ nums2[i]) + solve(nums1,nums2,pos+1,mask|(1<<i)));
            } 
        }
        return dp[pos][mask] = mi;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums1,nums2,0,0);
    }
};
