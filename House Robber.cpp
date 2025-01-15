class Solution {
public:
    // top down
    vector<int> dp;
    int f(vector<int> &arr,int i){
        if(i==arr.size()-1) return arr[i];
        if(i==arr.size()-2) return max(arr[i],arr[i+1]);
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(arr[i]+f(arr,i+2),f(arr,i+1));
    }

    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(105,-1);
        return f(nums,0);
    }
};
