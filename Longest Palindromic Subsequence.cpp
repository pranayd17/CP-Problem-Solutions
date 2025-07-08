class Solution {
public:

    vector<vector<int>> dp;
    int f(string &s1,string &s2,int i,int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=1+f(s1,s2,i-1,j-1);
        }
        else return dp[i][j]=max(f(s1,s2,i-1,j),f(s1,s2,i,j-1));
    }

    int longestPalindromeSubseq(string s) {
        string s2=s;
        int n=s.size(),m=n;
        reverse(s2.begin(),s2.end());
        dp.clear();
        dp.resize(n+1,vector<int>(n+1,-1));
        
        return f(s,s2,m-1,n-1);
    }
};
