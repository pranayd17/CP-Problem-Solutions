class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0); // dp[i] stores the max sum ending at index i
        deque<int> dq;       // Monotonic deque to store indices
        int maxSum = nums[0]; // Initialize the maximum sum
        
        dp[0] = nums[0];
        dq.push_back(0);

        for (int i = 1; i < n; ++i) {
            // Remove indices from the front of the deque if they are out of range
            if (!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }

            // Calculate dp[i] using the maximum dp value in the deque
            dp[i] = nums[i];
            if (!dq.empty()) {
                dp[i] += max(0, dp[dq.front()]);
            }

            // Update the maximum sum
            maxSum = max(maxSum, dp[i]);

            // Maintain the deque: remove indices from the back if dp[i] >= dp[dq.back()]
            while (!dq.empty() && dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }

            // Add the current index to the deque
            dq.push_back(i);
        }

        return maxSum;
    }
};
