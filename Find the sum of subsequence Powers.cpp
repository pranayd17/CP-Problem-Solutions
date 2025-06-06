class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        
        sort(nums.begin() , nums.end());
        int n = nums.size();
        
        vector < vector <int> > dp(n + 1 , vector <int> (k + 1));
        vector < int > skip(n , n);
        const int mod = 1e9 + 7;
        
        long long ans = 0;

        function < int(int , int) > memo = [&](int i ,int left) {
            if(left < 0) {
                return 0;
            }
            if(i == n) {
                if(left == 0) {
                    return 1;
                }
                return 0;
            }
            
            int &ans = dp[i][left];
            if(ans != -1) {
                return ans;
            }
            ans = memo(i + 1 , left);
            ans += memo(skip[i] , left - 1);
            ans %= mod;
            return ans;
        };
        
        map < int , int > doneDiff;
        map < int , long long , greater <int> > count;
        for(int i = 0;i<n;++i) {
            for(int j = i + 1;j<n;++j) {
                
                if(doneDiff[nums[j] - nums[i]]) continue;
                doneDiff[nums[i] - nums[j]] = 1;
                int x = 0;
                 for(int k = 0;k<n;++k) {
                     fill(dp[k].begin() , dp[k].end() , -1);
                    
                    while(x < n && nums[x] - nums[k] < nums[j] - nums[i]) ++x;
                    
                    skip[k] = x;

                }

                long long total = memo(0 , k);
                count[nums[j] - nums[i]] = total;
               
            }
           
        }
        
        long long last = 0;
        for(auto a : count) {
            long long current = a.second - last + mod;
            current += mod;
            current %= mod;
            ans += current * 1ll * a.first;
            ans %= mod;
            
            last = a.second;
        }
        return ans;
    }
};
