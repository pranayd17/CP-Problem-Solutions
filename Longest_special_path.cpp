class Solution {
public:
    int ansValue, ansLen;
    void dfs(int pre, int cur, int curDep, vector<vector<pair<int, int>>> &g, vector<int> &nums, vector<int> &arr, int l, unordered_map<int, int> &dep) {
        int prevDep = 0;
        if (dep.count(nums[cur])) prevDep = dep[nums[cur]];
        dep[nums[cur]] = curDep;

        l = max(l, prevDep);
        int curValue = arr.back() - arr[l];
        int curLen = curDep - l;
        if (ansValue < curValue || (ansValue == curValue && curLen < ansLen)) {
            ansValue = curValue;
            ansLen = curLen;
        }
        for (auto [nxt, val]: g[cur]) {
            if (nxt == pre) continue;
            arr.push_back(arr.back() + val);
            dfs(cur, nxt, curDep + 1, g, nums, arr, l, dep);
            arr.pop_back();
        }
        dep[nums[cur]] = prevDep;
    }

    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        ansValue = 0, ansLen = 1;
        int n = nums.size();
        vector<vector<pair<int, int>>> g(n);
        for (auto &x: edges) {
            g[x[0]].push_back({x[1], x[2]});
            g[x[1]].push_back({x[0], x[2]});
        }
        vector<int> arr;
        unordered_map<int, int> cnt;
        arr.push_back(0);
        cnt[nums[0]] = 0;
        dfs(-1, 0, 1, g, nums, arr, 0, cnt);
        return {ansValue, ansLen};
    }
};
