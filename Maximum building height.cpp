class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        sort(restrictions.begin(), restrictions.end());

        int len = restrictions.size();

        for (int idx = 1; idx < len; ++idx) {
            int currPos = restrictions[idx][0], prevPos = restrictions[idx - 1][0];
            int currHeight = restrictions[idx][1], prevHeight = restrictions[idx - 1][1];
            restrictions[idx][1] = min(currHeight, prevHeight + currPos - prevPos);
        }

        for (int idx = len - 2; idx >= 0; --idx) {
            int currPos = restrictions[idx][0], nextPos = restrictions[idx + 1][0];
            int currHeight = restrictions[idx][1], nextHeight = restrictions[idx + 1][1];
            restrictions[idx][1] = min(currHeight, nextHeight + nextPos - currPos);
        }

        int maxPossibleHeight = 0;
        for (int idx = 1; idx < len; ++idx) {
            int leftPos = restrictions[idx - 1][0], rightPos = restrictions[idx][0];
            int leftHeight = restrictions[idx - 1][1], rightHeight = restrictions[idx][1];
            maxPossibleHeight = max(maxPossibleHeight, max(leftHeight, rightHeight) + (rightPos - leftPos - abs(leftHeight - rightHeight)) / 2);
        }

        return maxPossibleHeight;
    }
};
