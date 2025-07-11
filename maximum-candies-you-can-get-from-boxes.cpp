class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
    int resCandies = 0;
    bool canOpenNewBox = true;
    while (!initialBoxes.empty() && canOpenNewBox) {
        canOpenNewBox = false;
        vector<int> nextBoxes{};
        for (const int& nextBoxId : initialBoxes) {
            if (status[nextBoxId]) {
                canOpenNewBox = true;
                nextBoxes.insert(end(nextBoxes), begin(containedBoxes[nextBoxId]), end(containedBoxes[nextBoxId]));
                for (const int& keyId : keys[nextBoxId])
                    status[keyId] = 1;
                resCandies += candies[nextBoxId];
            } else
                nextBoxes.push_back(nextBoxId);
        }
        swap(initialBoxes, nextBoxes);
    }
    return resCandies;
}
};
