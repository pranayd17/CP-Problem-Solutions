class Solution {
public:
    int mod=1e9+7;
    int sumOfPower(vector<int>& vec) {
        long long res=0;
        // Typecast the vector from int to long long
        vector<long long> nums(begin(vec), end(vec)); 
        sort(nums.begin(), nums.end());
        
        int n=nums.size();
        vector<int> prefix(n);
        prefix[0]=0;
        
        for(int i=1; i<n; i++)
            prefix[i] = ((2*prefix[i-1])+nums[i-1])%mod;
        
        for(int i=0; i<n; i++)
            prefix[i] = (prefix[i]+nums[i])%mod;
        
        //for(auto it: prefix)
        //        cout << it <<" ";
        cout << endl;
        for(int i=0; i<n; i++){
            res = (res+((long long)((long long)(nums[i]*nums[i])%mod)*prefix[i])%mod)%mod;
        }
        return res%mod;
    }
};
