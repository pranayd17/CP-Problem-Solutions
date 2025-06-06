class Solution {
 private:
  static constexpr int base = 10;

 public:
  vector<int> concatenatedDivisibility(const vector<int> &nums, const int k) {
    const int n = static_cast<int>(nums.size());
    const int n_layouts = 1 << n;
    optional<vector<int>> dp[n_layouts][k];
    dp[0][0] = make_optional(vector<int>{});
    for (int layout = 0; layout < n_layouts; ++layout) {
      for (int r = 0; r < k; ++r) {
        if (!dp[layout][r].has_value()) {
          continue;
        }

        vector<int> value = dp[layout][r].value();
        for (int i = 0; i < n; ++i) {
          if (((layout >> i) & 1) == 1) {
            continue;
          }

          value.emplace_back(nums[i]);
          const int next_layout = layout | (1 << i);
          const int next_r = (r * get_power10(nums[i]) + nums[i]) % k;
          if (!dp[next_layout][next_r].has_value() || value < dp[next_layout][next_r].value()) {
            dp[next_layout][next_r] = make_optional(value);
          }
          value.pop_back();
        }
      }
    }
    return dp[n_layouts - 1][0].value_or(vector<int>{});
  }

 private:
  int get_power10(const int num) {
    int ret = 1;
    for (int number = num; number > 0; number /= base) {
      ret *= base;
    }
    return ret;
  }
};
