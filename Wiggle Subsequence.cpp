class Solution {
public:
    int solve(vector<int> &temp,vector<int> &dp,int ind, int prev,int n)
{
    if(ind>=n)
        return 0;
    if(dp[prev+1]!=-1)
        return dp[prev+1];
    int take=0, nottake=solve(temp,dp,ind+1,prev,n);
    if(prev==-1 || (temp[prev]<0 && temp[ind]>=0) || (temp[prev]>=0 && temp[ind]<=0))
        take=1+solve(temp,dp,ind+1,ind,n);
    return dp[prev+1]=max(take,nottake);
}
int wiggleMaxLength(vector<int>& nums) {
    int n=nums.size();
    if(n<2)
        return n;
    vector<int> temp;
    for(int i=1;i<nums.size();i++)
    {
        int diff=nums[i]-nums[i-1];
        if(diff!=0)
            temp.push_back(diff);
    }
    vector<int> dp(n,-1);
    int size=temp.size();
    return 1+solve(temp,dp,0,-1,size);
}
};
