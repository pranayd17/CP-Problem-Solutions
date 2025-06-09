class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {

const int MOD = 1e9 + 7;
int n = nums.size();
vector<int> doran=nums;

    vector<int> dp(n + 1, 0);
    vector<int> prefix(n + 2, 0);
    dp[0] = 1;
    prefix[1] = 1;

    deque<int> minQ,maxQ;
    int left = 0;

    for (int right =0;right<n;++right) {
        while (!minQ.empty() && nums[minQ.back()] >= nums[right]) minQ.pop_back();
        while (!maxQ.empty() && nums[maxQ.back()] <= nums[right]) maxQ.pop_back();
        minQ.push_back(right);
        maxQ.push_back(right);
        while (nums[maxQ.front()] - nums[minQ.front()] > k) {
            if (minQ.front() == left) minQ.pop_front();
            if (maxQ.front() == left) maxQ.pop_front();
            ++left;
        }
        dp[right + 1] = (prefix[right + 1] - prefix[left] + MOD) % MOD;
        prefix[right + 2] = (prefix[right + 1] + dp[right + 1]) % MOD;
    }
    return dp[n];
    }
};
