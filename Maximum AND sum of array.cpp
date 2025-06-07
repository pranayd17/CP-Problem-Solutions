class Solution {
public:
    int dp[262145][20];  // dp[1<<(2*numSlots)][nums.length()+1]
    int f(int ind, vector<int> &nums, int vis[], int n, int dd){
        if(ind == nums.size()) {
            return 0;
        }
        if(dp[dd][ind]!=-1)return dp[dd][ind]; // memoization condition
        int ans = 0;
        for(int i=0;i<n;++i){
            if(vis[i]<2){
                vis[i]++;
                int ll = (vis[i]-1)*n+i; // find out bit to set in dd correspond to occupied slot..
                //[ i, n+i correspond to same slot.]
                int ff = (i+1)&(nums[ind]);  // calculate value for placing nums[ind] in ith slot
                ans = max(ans, ff+f(ind+1,nums,vis,n,dd^(1<<ll)));
                vis[i]--;
            }
        }
        return dp[dd][ind] = ans;
    }
    int maximumANDSum(vector<int>& nums, int n) {
        int ans = INT_MAX;
        int vis[20]={0};
        memset(dp,-1,sizeof(dp));
        return f(0,nums,vis,n,0);
    }
};
