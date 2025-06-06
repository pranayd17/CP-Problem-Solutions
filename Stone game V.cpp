class Solution {
public:
    int stoneGameV(vector<int>& a) {
        int n = a.size();
        if (n == 1)
            return 0;
        
        // Calculate the prefix sum of the array for quick range sum queries.
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + a[i];
        }
        
        // Initialize the memoization table to store the results of subproblems.
        vector<vector<int>> memo(n, vector<int>(n, -1));
        
        return stoneGameHelper(a, prefixSum, memo, 0, n - 1);
    }
    
    int stoneGameHelper(vector<int>& a, vector<int>& prefixSum, vector<vector<int>>& memo, int left, int right) {
        if (left == right)
            return 0;
        
        if (memo[left][right] != -1)
            return memo[left][right];
        
        int result = 0;
        for (int i = left; i < right; ++i) {
            int leftSum = prefixSum[i + 1] - prefixSum[left];
            int rightSum = prefixSum[right + 1] - prefixSum[i + 1];
            
            if (leftSum < rightSum) {
                result = max(result, leftSum + stoneGameHelper(a, prefixSum, memo, left, i));
            } else if (leftSum > rightSum) {
                result = max(result, rightSum + stoneGameHelper(a, prefixSum, memo, i + 1, right));
            } else {
                // If leftSum and rightSum are equal, consider both divisions.
                result = max(result, leftSum + max(
                    stoneGameHelper(a, prefixSum, memo, left, i),
                    stoneGameHelper(a, prefixSum, memo, i + 1, right)
                ));
            }
        }
        
        memo[left][right] = result;
        return result;
    }
};
